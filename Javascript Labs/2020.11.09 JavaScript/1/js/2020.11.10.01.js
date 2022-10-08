function Blur(number){

	let img = document.getElementsByTagName("img")[number-1];

	if(number==1) 
	{
		img.classList.toggle("greyBG")
	}
	if(number==2) 
	{
		img.classList.toggle("greyBG")
	}
	if(number==3) 
	{
		img.classList.toggle("greyBG")
	}
	if(number==4) 
	{
		img.classList.toggle("greyBG")
	}

	let button = document.getElementById("button" + number);
	button.classList.toggle("display");
	let text = document.getElementById("nameGood" + number);
	text.classList.toggle("display");
}