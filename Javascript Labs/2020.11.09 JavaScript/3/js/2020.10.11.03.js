function vote(){
	let checked = false;
	for(let i=1;i<7;i++)
	{
		if(document.getElementById("radio" + i).checked)
		{
			checked = true;
			break;
		}
	}

	if(checked)
	{
		document.getElementsByTagName("button")[0].style.display = "none";

		for(let i=1;i<7;i++)
		{
			document.getElementById("file" + i).style.visibility = "visible";
			document.getElementById("label" + i).style.visibility = "visible";
		}
	}
	else
	{
		alert("Выберите один из вариантов!")
	}
}