function livrareHome(){
	document.getElementById("LivrareSum").innerHTML = 25;
	total();
}

function livrareHere(){
	document.getElementById("LivrareSum").innerHTML = 0;
	total()
}

function total()
{
	let sum = +document.getElementById("LivrareSum").innerHTML;
	sum += +document.getElementById("subtotalSum").innerHTML
	document.getElementById("totalSum").innerHTML = sum;
}

function AmmoutPlus(){
	document.getElementById("sumPiz").innerHTML = 1 + +document.getElementById("sumPiz").innerHTML;
	document.getElementById("sumTotalForPiz").innerHTML = document.getElementById("sumPiz").innerHTML * 75;
	document.getElementById("subtotalSum").innerHTML = document.getElementById("sumTotalForPiz").innerHTML;
	total();
}

function AmmoutMinus(){
	if(document.getElementById("sumPiz").innerHTML!=1)
	{
		document.getElementById("sumPiz").innerHTML = +document.getElementById("sumPiz").innerHTML - 1;
		document.getElementById("sumTotalForPiz").innerHTML = +document.getElementById("sumTotalForPiz").innerHTML - 75;
		document.getElementById("subtotalSum").innerHTML = document.getElementById("sumTotalForPiz").innerHTML;
		total();
	}
	
}