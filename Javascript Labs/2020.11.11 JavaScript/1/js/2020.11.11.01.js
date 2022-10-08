function changeImage(number){
	let transport = ["Грузовик", "Велосипед", "Маршрутка", "Легковой автомобиль", "Спецтранспорт", "Самосвал", "Спецтранспорт", "Комбайн", "Мопед"]
	document.getElementById("definitionName").innerHTML = transport[number-1];
	document.getElementById("definitionImage").src = "../img/" + (number+1) + ".jpg";
}