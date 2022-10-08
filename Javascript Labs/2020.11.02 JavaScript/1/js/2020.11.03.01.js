let first = false;
let second = false;
let third = false;

let iFirst;
let iSecond;
let iThird;

function addFirst(){
	if(!first){
		document.getElementById("tItmes").innerHTML = 1 + +document.getElementById("tItmes").innerHTML;
		document.getElementById("tUnits").innerHTML = +document.getElementById("iFirst").value + +document.getElementById("tUnits").innerHTML;
		document.getElementById("tSum").innerHTML = +document.getElementById("iFirst").value * 29.00 + +document.getElementById("tSum").innerHTML;
		iFirst = document.getElementById("iFirst").value;
		first = true;
	}
	else if(document.getElementById("tItmes").innerHTML!=0)
	{
				document.getElementById("tSum").innerHTML =  +document.getElementById("tSum").innerHTML - iFirst * 29.00;
		document.getElementById("tUnits").innerHTML -= iFirst;
		document.getElementById("tItmes").innerHTML -= 1;
		first = false;
	}
	
}

function addSecond(){
	if(!second){
		document.getElementById("tItmes").innerHTML = 1 + +document.getElementById("tItmes").innerHTML;
		document.getElementById("tUnits").innerHTML = +document.getElementById("iSecond").value + +document.getElementById("tUnits").innerHTML;
		document.getElementById("tSum").innerHTML = +document.getElementById("iSecond").value * 45.00 + +document.getElementById("tSum").innerHTML;
		iSecond = document.getElementById("iSecond").value;
		second = true;
	}
	else if(document.getElementById("tItmes").innerHTML!=0)
	{
				document.getElementById("tSum").innerHTML = +document.getElementById("tSum").innerHTML - iSecond * 45.00;
		document.getElementById("tUnits").innerHTML -= iSecond;
		document.getElementById("tItmes").innerHTML -= 1;
		second = false;
	}
}

function addThird(){
	if(!third){
		document.getElementById("tItmes").innerHTML = 1 + +document.getElementById("tItmes").innerHTML;
		document.getElementById("tUnits").innerHTML = +document.getElementById("iThird").value + +document.getElementById("tUnits").innerHTML;
				document.getElementById("tSum").innerHTML = +document.getElementById("iThird").value * 24.00 + +document.getElementById("tSum").innerHTML;
		iThird = document.getElementById("iThird").value;
		third = true;
	}
	else if(document.getElementById("tItmes").innerHTML!=0)
	{
		document.getElementById("tSum").innerHTML = +document.getElementById("tSum").innerHTML - iThird * 24.00;
		document.getElementById("tUnits").innerHTML -= iThird;
		document.getElementById("tItmes").innerHTML -= 1;
		third = false;
	}
}