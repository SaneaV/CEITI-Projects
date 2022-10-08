var firstElem = 0;

function selectPict(number)
{
	document.getElementById("mainPng").src = document.getElementById("picture" + number).src;
}

function next(){
	if(firstElem==25)
	{
		document.getElementById("picture" + 1).src = "../img/" + 31 +".jpg";
		for(let i=2;i<6;i++)
		{
			document.getElementById("picture" + i).src = "../img/" + 32 +".jpg";
		}
	}
	else
	{
		firstElem = +firstElem + 5;
		for(let i=1;i<6;i++)
		{
			document.getElementById("picture" + i).src = "../img/" + +(firstElem+i) +".jpg";
		}
	}
}

function prev(){
	if(firstElem==0)
	{
		return;
	}
	else
	{
		firstElem = +firstElem - 5;
		for(let i=1;i<6;i++)
		{
			document.getElementById("picture" + i).src = "../img/" + +(firstElem+i) +".jpg";
		}
	}
}