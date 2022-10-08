$('#inputTask').bind("enterKey",function(e) {
	let text = $('#inputTask').val();
	$('#tasks').append('<div id="task"><input type="checkbox" id="checkboxTask"/> ' + text + ' <img src="../img/1.png"> </div> <br /');
	$('#inputTask').val("");
});

$('#inputTask').keyup(function(e){
	if(e.keyCode == 13)
	{
		$(this).trigger("enterKey");
	}
});


$('#tasks').on('click','#checkboxTask', function() {
	$(this).parent().css('color','grey');
	$(this).parent().wrap("<strike>");
	$(this).hide();
	$(this).parent().css('color','grey');
	$(this).parent().css({'padding-left':'27px'});
});


$('body').on('click','img',function(){
	$(this).parent('div').remove();
})

$('body').on('dblclick','#task',function(){
	let checkboxes = $(this).find("input[type=checkbox]");

	if(!checkboxes.prop('checked'))
	{
		$(this).empty();
		$(this).append('<input type="text" id="temp">');
		$("#temp").css('width','98%');
		$("#temp").focus();
	}

})


$('body').on('keypress','#task',function(e){

	if(e.keyCode == 13)
	{
		let text = $('#temp').val();
		$(this).append('<input type="checkbox" id="checkboxTask"/> ' + text + ' <img src="../img/1.png"> <br />');
		$('#temp').remove();
	}	
});