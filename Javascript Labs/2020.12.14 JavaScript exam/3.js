let to = "usd";
let from = "mdl";

$(document).ready(function() {
	var date = new Date();

	var day = date.getDate();
	var month = date.getMonth() + 1;
	var year = date.getFullYear();

	if (month < 10) month = "0" + month;
	if (day < 10) day = "0" + day;

	var today = year + "-" + month + "-" + day;       
	$("#theDate").attr("value", today);

	$("#mdlFrom").css("background-color", "silver");
	$("#usdTo").css("background-color", "silver");
});

$("#mdlTo").click(function(){
	if(!(from=="mdl")){
		resetTo();
		$("#mdlTo").css("background-color", "silver");
		$("#labelTo").text("MDL");
		to = "mdl";
	}
})

$("#usdTo").click(function(){
	if(!(from=="usd")){
		resetTo();
		$("#usdTo").css("background-color", "silver");
		to = "usd";
		$("#labelTo").text("USD");

	}
})

$("#eurTo").click(function(){
	if(!(from=="eur")){
		resetTo();
		$("#eurTo").css("background-color", "silver");
		to = "eur";
		$("#labelTo").text("EUR");

	}
})

$("#rubTo").click(function(){
	if(!(from=="rub")){
		resetTo();
		$("#rubTo").css("background-color", "silver");
		to = "rub";
		$("#labelTo").text("RUB");
	}
})

$("#ronTo").click(function(){
	if(!(from=="ron")){
		resetTo();
		$("#ronTo").css("background-color", "silver");
		to = "ron";
		$("#labelTo").text("RON");
	}
})


$("#mdlFrom").click(function(){
	if(!(to=="mdl")){
		resetFrom()
		$("#mdlFrom").css("background-color", "silver");
		from = "mdl";
		$("#labelFrom").text("MDL");
	}
})

$("#usdFrom").click(function(){
	if(!(to=="usd")){
		resetFrom()
		$("#usdFrom").css("background-color", "silver");
		from = "usd";
		$("#labelFrom").text("USD");
	}
})

$("#eurFrom").click(function(){
	if(!(to=="eur")){
		resetFrom()
		$("#eurFrom").css("background-color", "silver");
		from = "eur";
		$("#labelFrom").text("EUR");
	}
})

$("#rubFrom").click(function(){
	if(!(to=="rub")){
		resetFrom()
		$("#rubFrom").css("background-color", "silver");
		from = "rub";
		$("#labelFrom").text("RUB");
	}
})

$("#ronFrom").click(function(){
	if(!(to=="ron")){
		resetFrom()
		$("#ronFrom").css("background-color", "silver");
		from = "ron";
		$("#labelFrom").text("RON");
	}
})


function resetTo(){

	$("#valutes2").children().each(function(){
		$(this).css("background-color", "grey");
		$("#inputFrom").val("");
		$("#inputTo").val("");
	})

}

function resetFrom(){
	$("#valutes1").children().each(function(){
		$(this).css("background-color", "grey");
		$("#inputFrom").val("");
		$("#inputTo").val("");
	})
}

$('#inputTo').on('input', function() {
	let valueMoney = [0,0,0,0,0];
	if(to=="mdl")
	{
		valueMoney[0] = $(this).val();
		valueMoney[1] = $(this).val()*0.06;
		valueMoney[2] = $(this).val()*0.05;
		valueMoney[3] = $(this).val()*4.18
		valueMoney[4] = $(this).val()*0.23;

	}
	if(to=="usd")
	{
		valueMoney[0] = $(this).val()*17.12;
		valueMoney[1] = $(this).val();
		valueMoney[2] = $(this).val()*0.82;
		valueMoney[3] = $(this).val()*71.63;
		valueMoney[4] = $(this).val()*3.98;
	}
	if(to=="eur")
	{
		valueMoney[0] = $(this).val()*20.71;
		valueMoney[1] = $(this).val()*1.20;
		valueMoney[2] = $(this).val();
		valueMoney[3] = $(this).val()*86.65;
		valueMoney[4] = $(this).val()*4.82;
	}
	if(to=="rub")
	{
		valueMoney[0] = $(this).val()*0.23;
		valueMoney[1] = $(this).val()*0.01;
		valueMoney[2] = $(this).val()*0.01;
		valueMoney[3] = $(this).val();
		valueMoney[4] = $(this).val()*0.05;
	}
	if(to=="ron")
	{
		valueMoney[0] = $(this).val()*4.1;
		valueMoney[1] = $(this).val()*0.24;
		valueMoney[2] = $(this).val()*0.2;
		valueMoney[3] = $(this).val()*17.15;
		valueMoney[4] = $(this).val();
	}

	if(from=="mdl")
	{
		$("#inputFrom").val(valueMoney[0]);
	}
	if(from=="usd")
	{
		$("#inputFrom").val(valueMoney[1]);
	}
	if(from=="eur")
	{
		$("#inputFrom").val(valueMoney[2]);
	}
	if(from=="rub")
	{
		$("#inputFrom").val(valueMoney[3]);
	}
	if(from=="ron")
	{
		$("#inputFrom").val(valueMoney[4]);
	}
});

$('#inputFrom').on('input', function() {
	let valueMoney = [0,0,0,0,0];
	if(from=="mdl")
	{
		valueMoney[0] = $(this).val();
		valueMoney[1] = $(this).val()*0.06;
		valueMoney[2] = $(this).val()*0.05;
		valueMoney[3] = $(this).val()*4.18
		valueMoney[4] = $(this).val()*0.23;

	}
	if(from=="usd")
	{
		valueMoney[0] = $(this).val()*17.12;
		valueMoney[1] = $(this).val();
		valueMoney[2] = $(this).val()*0.82;
		valueMoney[3] = $(this).val()*71.63;
		valueMoney[4] = $(this).val()*3.98;
	}
	if(from=="eur")
	{
		valueMoney[0] = $(this).val()*20.71;
		valueMoney[1] = $(this).val()*1.20;
		valueMoney[2] = $(this).val();
		valueMoney[3] = $(this).val()*86.65;
		valueMoney[4] = $(this).val()*4.82;
	}
	if(from=="rub")
	{
		valueMoney[0] = $(this).val()*0.23;
		valueMoney[1] = $(this).val()*0.01;
		valueMoney[2] = $(this).val()*0.01;
		valueMoney[3] = $(this).val();
		valueMoney[4] = $(this).val()*0.05;
	}
	if(from=="ron")
	{
		valueMoney[0] = $(this).val()*4.1;
		valueMoney[1] = $(this).val()*0.24;
		valueMoney[2] = $(this).val()*0.2;
		valueMoney[3] = $(this).val()*17.15;
		valueMoney[4] = $(this).val();
	}

	if(to=="mdl")
	{
		$("#inputTo").val(valueMoney[0]);
	}
	if(to=="usd")
	{
		$("#inputTo").val(valueMoney[1]);
	}
	if(to=="eur")
	{
		$("#inputTo").val(valueMoney[2]);
	}
	if(to=="rub")
	{
		$("#inputTo").val(valueMoney[3]);
	}
	if(to=="ron")
	{
		$("#inputTo").val(valueMoney[4]);
	}

	
});