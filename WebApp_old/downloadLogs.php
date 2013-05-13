<?php
//get date
#$date = 26092012;
$date = str_replace("/","",$_GET["date"]);
$anchorFile = "anchor.txt";
$anchor = fopen($anchorFile, 'w') or die("can't open file");
fwrite($anchor, $date);
fclose($anchor) or die("can't close file");
exec("FileDownloader.exe");
?>