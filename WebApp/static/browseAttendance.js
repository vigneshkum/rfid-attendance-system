$(document).ready(function()
{
	$( "#datepicker" ).datepicker({
			changeMonth: true,
			changeYear: true,
			dateFormat: "dd/mm/yy"
		});
});

function updateReport(){
	var date = $("#datepicker").val();
	$("div#report").load("getReport.php?date="+date);
	//$("div#report").load("test.php?date="+date);
	$("#reportTable").addClass("gridtable");
}

function downloadRecord(){
	var date = $("#datepicker").val();
	//$("div#report").load("getReport.php?date="+date);
	$.get("downloadLogs.php?date="+date);
}

function redirect(){
	window.location.href = "updateUser.php";
}