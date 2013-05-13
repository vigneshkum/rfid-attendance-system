<?php
//get date
#$date = 26092012;
$date = str_replace("/","",$_GET["date"]);

$logFile = "logs\\".$date.".txt";
$userFile = "data\\users.txt";
$reportFile = "reports\\report_".$date.".txt";

//echo $logFile;
//echo $reportFile;

//check if report is present, otherwise generate it
//if(file_exists($reportFile)){
//	displayReport($date);
//}else{	
	if(file_exists($logFile)){
		$uFile = fopen($userFile,'r') or die("can't open file");
		$report = fopen($reportFile, 'w') or die("can't open file");
		while($user_line = fgetcsv($uFile,1024)) {
			$userID = $user_line[0];
			$inTime = "unknown";
			$outTime = "unknown";
			$timeSpent="unknown";
			$first = 1;
			//Open log file and process it
			$fp = fopen($logFile,'r') or die("can't open file");
			while($csv_line = fgetcsv($fp,1024)) {
				if($userID==$csv_line[1]){
					//Record First Entry
					if($first){
						$inTime=$csv_line[0];
						$first = 0;
					}else{
						$outTime=$csv_line[0];
					}
				}
			}
			fclose($fp) or die("can't close file");
			//Time Calculation
			$in =  explode(':', $inTime);
			$out = explode(':', $outTime);
			if( ($out[1]-$in[1]) < 0){
				$timeSpent = (($out[0]-$in[0])-1)."h ".(($out[1]-$in[1])+60)."m";
			}else{
				$timeSpent = ($out[0]-$in[0])."h ".($out[1]-$in[1])."m";
			}
			$reportEntry = chop($user_line[2],';').",".chop($user_line[1],';').",".$userID.",".$inTime.",".$outTime.",".$timeSpent."\n";
			fwrite($report, $reportEntry);
			//print $reportEntry;
		}
		fclose($report);
		fclose($uFile) or die("can't close file");
		displayReport($date);
	}else{
		echo "Log File ".$date.".txt does not exist";	
	}
//}

function displayReport($date){
	$reportFile = "reports\\report_".$date.".txt";
	//open and display report
	$fp = fopen($reportFile,'r') or die("can't open file");
		print "<center><table id='reportTable' class='gridtable' border='1'>\n";
		print "<thead><tr><th>EMP ID</th><th>Name</th><th>UID</th><th>In-Time</th><th>Out-Time</th><th>Total Time</th></tr></thead><tbody>\n";
		while($csv_line = fgetcsv($fp,1024)) {
			print '<tr>';
			for ($i = 0, $j = count($csv_line); $i < $j; $i++) {
				print '<td>'.$csv_line[$i].'</td>';
			}
			print "</tr>\n";
		}
		print "</tbody></table></center>\n";
		fclose($fp) or die("can't close file");
}
?>