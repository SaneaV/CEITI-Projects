var array = [];

function createTable()
{
	let n = prompt("Введите размерность", 5);
	let m = prompt("Введите время", 30);
	document.getElementById("timeleft").innerHTML = m;
	let table=document.createElement("table");
	let all = (n*n);
	let randomArray = random(all);
	all--;

	let colors = ['red', 'black', 'green', 'orange', 'yellow', 'navi', 'blue', 'pink', 'brown', 'silver', 'grey'];


	for (let i=0; i<n; i++) 
	{
		let row=table.insertRow(0);

		for(let j=0; j<n;j++)
		{
			let cell = row.insertCell(0);
			cell.innerHTML = randomArray[(all--)];
			cell.style.color = colors[Math.floor(Math.random() * colors.length)];
			cell.style.fontSize = +10 + Math.random() * 20 + "px";

		}
	}

	document.getElementById("mainBlock").appendChild(table);
	let button=document.createElement("button");
	button.innerHTML = "Начать сначала"
	
	button.onclick = function() {
		location.reload()
	};

	document.getElementById("mainBlock").appendChild(button);
	start();


	table.onclick = function(event) {
		let target = event.target;

		if (target.tagName != 'TD') return; 

		if(array.length==0 && target.innerHTML==1){
			array.push(1);
			target.style.backgroundColor = "red";
		}
		else if(array.length==(target.innerHTML-1))
		{
			array.push(target.innerHTML);
			target.style.backgroundColor = "red";
		}

		if(array.length==(n*n))
		{
			alert("Поздравляем! Вы выиграли!");
			location.reload()
		}
	}
}


function random(n){

	let randomArray = [];

	for(let i=0;i<n;i++)
	{
		randomArray[i] = (1+i);
	}

	return shuffle(randomArray);
}

function shuffle(array) {
	var currentIndex = array.length, temporaryValue, randomIndex;

	while (0 !== currentIndex) {
		randomIndex = Math.floor(Math.random() * currentIndex);
		currentIndex -= 1;
		temporaryValue = array[currentIndex];
		array[currentIndex] = array[randomIndex];
		array[randomIndex] = temporaryValue;
	}
	return array;
}

function start(){
	let seconds = document.body.getElementsByTagName('span')[0].innerHTML;
	if(seconds!="Ошибка!")
	{
		seconds--;

		if(seconds>=0)
		{
			document.body.getElementsByTagName('span')[0].innerHTML = seconds;
			t = setTimeout(start, 1000);
		}
		else{
			alert("Игра закончена! Вы проиграли!");
			location.reload();
		}
	}		    
}


