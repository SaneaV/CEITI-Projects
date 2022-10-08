function exchange(){
	let ammount = document.getElementById("ammount").value;

	let valute = document.getElementById("valutSelector").value;
	
	if(valute == "eur")
	{
		document.getElementById("valutName").innerHTML = "Euro";
		document.getElementById("mdl").innerHTML = 19.91 * ammount + " leu";
		document.getElementById("eur").innerHTML = ammount + " eur";
		document.getElementById("usd").innerHTML = 1.3 * ammount + " usd";
	}
	if(valute == "mdl")
	{
		document.getElementById("valutName").innerHTML = "Lei";
		document.getElementById("mdl").innerHTML = ammount + " leu";
		document.getElementById("eur").innerHTML = 0.05 * ammount + " eur";
		document.getElementById("usd").innerHTML = 0.06 * ammount + " usd";
	}
	else if(valute=="usd")
	{
		document.getElementById("valutName").innerHTML = "Dollar";
		document.getElementById("mdl").innerHTML = Math.round(17 * ammount) + " leu";
		document.getElementById("eur").innerHTML = Math.round(0.90 * ammount) + " eur";
		document.getElementById("usd").innerHTML = ammount + " usd";
	}
}