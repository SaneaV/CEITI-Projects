let step = 0;
let matrixField = ([[0, 0, 0], [0, 0, 0], [0, 0, 0]]);
let win = false;

function reset(){
	$('#field td').each(function() {
		$(this).empty();
	});

	step = 0;
	matrixField = ([[0, 0, 0], [0, 0, 0], [0, 0, 0]]);
	win = false;
	$("#action").text("Начните игру");
}

$("#field td").click(function(){
	if($(this).text() == "" && !win)
	{
		if(step%2==0) $(this).text("x");
		else $(this).text("o");

		let j = $(this).index();
		let i = $(this).parent().index();
		if(step%2==0) matrixField[i][j] = 1;
		else matrixField[i][j] = 2;
		win = isItWin();

		if(win){
			let winner = 0;
			if(step%2==0) 
			{
				winner = "x";
				let i = $("#xWon").text();
				i++;
				$("#xWon").text(i);
			}
			else 
			{
				winner = "o";
				let i = $("#oWon").text();
				i++;
				$("#oWon").text(i);
			}
			$("#action").text("Выиграл: " + winner);
		}
		else if(step==8){
			$("#action").text("Ничья!");
			let i = $("#draw").text();
			i++;
			$("#draw").text(i);
		}
		else{
			step++;
		}
	}


});

function isItWin(){
	for(let i=0;i<3;i++)
	{
		let temp1 = matrixField[i][0];
		let temp2 = matrixField[0][i];

		if(temp1 == matrixField[i][1] && temp1!=0)
		{
			if(temp1==matrixField[i][2] && temp1)
			{
				return true;
			}
		}

		if(temp2 == matrixField[1][i] && temp2!=0)
		{
			if(temp2==matrixField[2][i])
			{
				return true;
			}
		}
	}

	let temp3 = matrixField[1][1];

	if(temp3 == matrixField[0][0] && temp3!=0)
	{
		if(temp3 == matrixField[2][2])
		{
			return true;
		}
	}
	if(temp3 == matrixField[0][2] && temp3!=0)
	{
		if(temp3 == matrixField[2][0])
		{
			return true;
		}
	}

	return false;
}
