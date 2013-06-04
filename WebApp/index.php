<html>
<head>
	<title>RFID ATTENDANCE SYSTEM</title>
	<!--JS Files-->
	<script type="text/javascript" src="static/lib/js/jquery-1.6.2.min.js"></script>
	<script type="text/javascript" src="static/lib/js/jquery-ui-1.8.16.custom.min.js"></script>
	<script type="text/javascript" src="static/lib/js/jquery.dataTables.min.js"></script>
	<script type="text/javascript" src="static/updateUser.js"></script>
	<!--CSS Files-->
	<link type="text/css" href="static/lib/css/ui-darkness/jquery-ui-1.8.16.custom.css" rel="stylesheet" />	
	<link type="text/css" href="static/lib/css/ui-darkness/jquery.dataTables.css" rel="stylesheet" />	
	<link type="text/css" href="static/lib/css/ui-darkness/jquery.dataTables_themeroller.css" rel="stylesheet" />	
	<link rel="stylesheet" type="text/css" href="static/base.css">
	<link rel="stylesheet" type="text/css" href="static/browseAttendance.css">
</head>
<body>
<div id="header"><b>
<span style="color:blue;">Deepak Electrical Insulation Pvt Ltd</span> <br/><br/>
<span style="color:brown;font-size:20;">ADD / DELETE USER</span><br/><br/>
</b></div>
<div id="newUser" class="curvedShadow center">
	<input type="button" id="addNewUser" value="ADD NEW USER" onclick="showPopUp()">
</div>
<br/>
<div id="users" class="curvedShadow center">
<?php
$userFile = "data\\users.TXT";
	if(file_exists($userFile)){
		$uFile = fopen($userFile,'r') or die("can't open file");
		print "<center><table id='reportTable' class='gridtable' border='1'>\n";
		print "<thead><tr><th>EMP ID</th><th>Name</th><th>UID</th><th></th></tr></thead><tbody>\n";
		while($user_line = fgetcsv($uFile,1024)) {
			$cardID = $user_line[0];
			$empID = chop($user_line[2],';');
			$name = $user_line[1];
			print "<tr>";
			print "<td>".$empID."</td>";
			print "<td>".$name."</td>";
			print "<td>".$cardID."</td>";
			print "<td><input type='button' value='Delete' onclick='deleteUser($empID)'/></td>";
			/*
			print "<td><input type='button' value='Update' onclick='updateUser($empID,\"$name\",\"$cardID\")'/></td>";
			*/
			print "</tr>\n";
		}
		print "</tbody></table></center>\n";
		fclose($uFile) or die("can't close file");
	}else{
		echo "Cannot open ".$userFile.".TXT";	
	}
?>
</div>
<!--
<div id="updateRecord" >
<br/>
<center>
<table style="color:white;font-weight:bold;">
<tr><td >EMP ID </td><td>: <input type="text" id="emp" /></td></tr>
<tr><td>Name </td><td>: <input type="text" id="name" /></td></tr>
<tr><td>Card ID </td><td>: <input type="text" id="card" /></td></tr>
</table>
</center>
<br/>
</div>
-->

<div id="addRecord" >
<br/>
<center>
<table style="color:white;font-weight:bold;">
<tr><td >EMP ID </td><td>: <input type="text" id="newemp" /></td></tr>
<tr><td>Name </td><td>: <input type="text" id="newname" /></td></tr>
<tr><td>Card ID </td><td>: <input type="text" id="newcard" /><input type="button" id="swipe" value="Swipe" onclick="downloadID()"><input type="button" id="getID" value="Insert" onclick="getID()"></td></tr>
</table>
</center>
<br/>
</div>
</body>
</html>