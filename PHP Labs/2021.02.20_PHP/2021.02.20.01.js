$('#addButton').click(function(){
	$('#add').removeClass("hide");
	$('#show').addClass("hide");
	$('#delete').addClass("hide");
	$('#homePage').addClass("hide");
})

$('#deleteButton').click(function(){
	$('#delete').removeClass("hide");
	$('#show').addClass("hide");
	$('#add').addClass("hide");
	$('#homePage').addClass("hide");
})

$('#showButton').click(function(){
	$('#show').removeClass("hide");
	$('#delete').addClass("hide");
	$('#add').addClass("hide");
	$('#homePage').addClass("hide");
})



$('body').ready(function(){
	$('#add').addClass("hide");
	$('#delete').addClass("hide");
})