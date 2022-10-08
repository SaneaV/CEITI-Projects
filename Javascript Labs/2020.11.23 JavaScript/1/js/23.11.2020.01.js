function allowDrop(ev) {
	ev.preventDefault();
}

function drag(ev) {
	ev.dataTransfer.setData("text", ev.target.id);
}

function drop(ev) {
	ev.preventDefault();
	var data = ev.dataTransfer.getData("text");
	ev.target.appendChild(document.getElementById(data));

	if(ev.target.classList.contains("Basket"))
	{
		deleteElem();
	}
}

function deleteElem() {
	const parent = document.getElementsByClassName("Basket")[0];
	parent.lastChild.remove()
}