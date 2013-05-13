<html>
<head>
	<title>Attendance Browser</title>
	<!--JS Files-->
	<script type="text/javascript" src="static/lib/js/jquery-1.6.2.min.js"></script>
	<script type="text/javascript" src="static/lib/js/jquery-ui-1.8.16.custom.min.js"></script>
	<script type="text/javascript" src="static/lib/js/jquery.dataTables.min.js"></script>
	<script type="text/javascript" src="static/browseAttendance.js"></script>
	<!--CSS Files-->
	<link type="text/css" href="static/lib/css/ui-darkness/jquery-ui-1.8.16.custom.css" rel="stylesheet" />	
	<link type="text/css" href="static/lib/css/ui-darkness/jquery.dataTables.css" rel="stylesheet" />	
	<link type="text/css" href="static/lib/css/ui-darkness/jquery.dataTables_themeroller.css" rel="stylesheet" />	
	<link rel="stylesheet" type="text/css" href="static/base.css">
	<link rel="stylesheet" type="text/css" href="static/browseAttendance.css">
</head>
<body>
<div  style="text-align:right">
<input type="button" id="addEditUser" value="ADD / EDIT USER" onclick="redirect()">
</div>
<div id="header"><b>
<span style="color:blue;">Deepak Electrical Insulation Pvt Ltd</span> <br/><br/>
<span style="color:brown;font-size:20;">Attendance Sheet</span><br/><br/>
</b></div>
<div id="calender" class="curvedShadow center">
	<b>Date:</b> <input type="text" id="datepicker">
	<input type="button" id="download" value="Download" onclick="downloadRecord()">
	<input type="button" id="showRecord" value="Display Records" onclick="updateReport()">
</div>
<br/>
<div id="report" class="curvedShadow center">

</div>
</body>
</html>