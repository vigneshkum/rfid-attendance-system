$(function() {
		/*
		$( "#updateRecord" ).dialog({
			resizable: true,
			//height:140,
			width:500,
			modal: true,
			buttons: {
				"Update Record": updateRecord(),
				Cancel: function() {
					$( this ).dialog( "close" );
				}
			}
		});
		$( "#updateRecord"  ).dialog( "close" );
		*/
		$( "#addRecord:ui-dialog" ).dialog( "destroy" );
	
		$( "#addRecord" ).dialog({
			resizable: true,
			//height:140,
			width:500,
			modal: true,
			buttons: {
				"Add Record": function() {
					//$( this ).dialog( "close" );
					var emp = $( "#newemp" ).val();
					var name = $( "#newname" ).val();
					var card = $( "#newcard" ).val();
					$.get("addUser.php?empID="+emp+"&name="+name+"&cardID="+card,function(){
						location.reload();
					});
				},
				Cancel: function() {
					$( this ).dialog( "close" );
				}
			}
		});
		$( "#addRecord"  ).dialog( "close" );
	});

function deleteUser(empID){
	//alert("hello "+empID);
	$.get("deleteUser.php?ID="+empID,function(){
		location.reload();
	});
}

function updateUser(emp,name,card){
	//alert(emp+name+card);
	$( "#emp" ).val(emp);
	$( "#name" ).val(name);
	$( "#card" ).val(card);
	$( "#updateRecord" ).dialog( "open" );
}
/*
function updateRecord(){
	var emp = $( "#emp" ).val();
	var name = $( "#name" ).val();
	var card = $( "#card" ).val();
	$.get("editUser.php?ID="+emp+"&name="+name+"&card="+card,function(){
		location.reload();
	});
}*/

function showPopUp(){
	$( "#addRecord"  ).dialog( "open" );
}

function getID(){
	$.get("getCardID.php",function(data){
		$( "#newcard" ).val(data);;
	});
}

function downloadID(){
	$.get("downloadCardID.php");
}