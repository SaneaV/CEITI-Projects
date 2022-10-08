function clockTick(){
	let date = new Date();
	let HH = date.getHours();
	let MM = date.getMinutes();
	let SS = date.getSeconds();

	if(HH<10)
		HH =  "0" + HH;
	if(MM<10)
		MM =  "0" + MM;
	if(SS<10)
		SS =  "0" + SS;

	let time = ("" + HH +":" + MM+"." + SS).split('');

	for(let i=0;i<time.length;i++)
	{	
		if(i==2 || i==5)
			continue;

		setRis(time[i], i)
	}

	setTimeout("clockTick()", 1000);
}

function setRis(number, position)
{	
	let image = document.getElementsByTagName("img")[position];
	document.getElementsByTagName("img")[position].src = "../img/dg" + number + ".gif";	
}

