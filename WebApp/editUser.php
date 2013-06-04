<?php

$emp = $_GET["ID"];
$name = $_GET["name"];
$card = $_GET["card"];

$userFile = "data\\users.txt";
$userTemp = "data\\users_temp.txt";

$uFile = fopen($userFile,'r') or die("can't open file");
$temp = fopen($userTemp, 'w') or die("can't open file");
while($user_line = fgetcsv($uFile,1024)) {
			$cardID = $user_line[0];
			$empID = chop($user_line[2],';');
			$name = $user_line[1];
			if($ID != $empID){
				$Entry = $cardID.",".$name.",".$empID.";\n";
				fwrite($temp, $Entry);
			}
		}
fclose($temp) or die("can't close file");
fclose($uFile) or die("can't close file");
exec("move ".$userTemp." ".$userFile);
?>