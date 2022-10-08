function doSomething(elem){
	var alt = document.createTextNode( elem.getAttribute('alt') );
	elem.parentNode.insertBefore( alt, elem );
	elem.parentNode.removeChild( elem );
}

function openRis(poz){
	let ris = ["ar13", "null", "el15", "el16", "null", "sa18"];
	let model = ["Ariston MW 212", "Ariston MWO 323 IX", "Electrolux EMS 2390", "Electrolux EMM 1900", "Samsung CE1190R", "Samsung C106R"];	
	let text = "";

	if(ris[poz] == "null")
		text = "Для этой модели фотографии нет!";
	else{
		text = "<img src=\"../img/" + ris[poz] + ".jpg\" width=\"250px\" height=\"200px\">";
	}

	let params = `scrollbars=no,resizable=no,status=no,location=no,toolbar=no,menubar=no,
	width=300,height=200,left=250,top=350`;

	let newWin = window.open("about:blank", model[poz], params);
	newWin.document.write(text);
}