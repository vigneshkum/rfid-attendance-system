<?php
$empID = $_GET["empID"];
$name = $_GET["name"];
$cardID = $_GET["cardID"];

$userFile = "data\\users.txt";

$uFile = fopen($userFile,'a') or die("can't open file");
$Entry = $cardID.",".$name.",".$empID.";\n";
fwrite($uFile, $Entry);
fclose($uFile) or die("can't close file");

$userFile = "data\\userdb.txt";
$uFile = fopen($userFile,'a') or die("can't open file");
$Entry = $cardID.",".$name.";\n";
fwrite($uFile, $Entry);
fclose($uFile) or die("can't close file");
?>