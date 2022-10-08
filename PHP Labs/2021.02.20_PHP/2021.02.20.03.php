<?php

if($_SERVER['REQUEST_METHOD'] == "POST" and isset($_POST['show']))
{
	func();
}
function func()
{
	$file = fopen("books.txt","r");
	$allLines = "<table>";

	while(!feof($file)){

		
		$line = fgets($file);
		$splitted = explode('*', $line);

		if(empty($line))
		{

		}
		else
		{
			$allLines.= "<tr>";
			$allLines.= "<td>".$splitted[0]."</td>"."<td>".$splitted[1]."</td>"."<td>".$splitted[2]."</td>"."<td>".$splitted[3]."</td>"."<td>".$splitted[4]."</td>"."<td>".$splitted[5]."</td>";
			$allLines.= "</tr>";
		}



	}

	fclose($file);
	$allLines.= "</table>";

	echo '<!DOCTYPE html>
	<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>Книги</title>
	<link rel="stylesheet" href="2021.02.20.01.css">
	<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
	</head>
	<body>

	<div class="mainBody">

	<div class="buttons">

	<form action="2021.02.20.03.php" method="post">
	<input type="submit" value="Показать" id="showButton" name="show">
	</form>
	<button id="addButton">Добавить</button>
	<button id="deleteButton">Удалить</button>

	</div>

	<div class="actions">

	<div id="add">
	<form action="2021.02.20.01.php" method="GET">
	<label for="Title">Название:</label>
	<input type="text" class="Title" name="titleAdd"><br>

	<label for="Author">Автор:</label>
	<input type="text" class="Author" name="authorAdd"><br>

	<label for="Manufacter">Издательство:</label>
	<input type="text" class="Manufacter" name="manufacter"><br>

	<label for="Year">Год издания:</label>
	<input type="number" class="Year" name="year" min="0" max="2021" style="width: 170px"><br>

	<label for="Type">Жанр:</label>
	<input type="text" class="Type" name="type"><br>

	<label for="Language">Язык:</label>
	<input type="text" class="Language" name="language"><br>

	<input type="submit">
	</form>

	</div>

	<div id="delete">
	<form action="2021.02.20.02.php" method="GET">
	<label for="Title">Название:</label>
	<input type="text" class="Title" name="titleDelete"><br>

	<label for="Author">Автор:</label>
	<input type="text" class="Author" name="authorDelete"><br>

	<input type="submit">
	</form>

	</div>

	<div id="show">
	'.$allLines.'

	</div>
	</div>
	</div>

	<script src="2021.02.20.01.js"></script>
	
	</body>
	</html>';
}

?>