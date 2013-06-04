<?php
$idFile = "data\\cardID.txt";
$uFile = fopen($idFile,'r') or die("can't open file");
$id = fgets($uFile,1024);
fclose($uFile) or die("can't close file");
print $id
?>