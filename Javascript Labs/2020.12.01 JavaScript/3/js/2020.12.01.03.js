$('#button').click(function(){
	let check = true;

	if(!$("input[name='1']:checked").length)
	{
		$("#first").append("<div id='noAnswer1'>Вы не предоставили ответ</div>");
		$("#noAnswer1").css('color','red');
	}
	
	if(!$("input[name='2']:checked").length)
	{
		$("#second").append("<div id='noAnswer2'>Вы не предоставили ответ</div>");
		$("#noAnswer2").css('color','red');
	}
	if(!$("input[name='3']:checked").length)
	{
		$("#third").append("<div id='noAnswer3'>Вы не предоставили ответ</div>");
		$("#noAnswer3").css('color','red');
	}

	changeColor();
	$("#radio2").next().css('color', 'green');
	$("#radio4").next().css('color', 'green');
	$("#radio9").next().css('color', 'green');

	let rightAnswer = 0;

	if ($("#radio2").is(":checked")) {
		rightAnswer++;
	}if ($("#radio4").is(":checked")) {
		rightAnswer++;
	}if ($("#radio9").is(":checked")) {
		rightAnswer++;
	}
	$("#mainBlock").append("Правильных ответов: " + (rightAnswer) +" <br> Неправильных ответов: " +  (3 - rightAnswer));
	$(this).remove();
});


function changeColor ()
{	
	$("input[name=1]:checked").next().css('color', 'red');
	$("input[name=2]:checked").next().css('color', 'red');
	$("input[name=3]:checked").next().css('color', 'red');
}