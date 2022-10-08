<?php
echo "Простые числа: ";
for($i=2;$i<100;$i++){
	$simple = true;
	for($j=2;$j<($i/2)+1;$j++)
	{
		if($i%$j==0 && $simple) $simple = false;
	}

	if($simple) echo $i." ";
}


echo "<br><br><br>Таблица умножения: <br><table>";

for($i=1;$i<11;$i++)
{
	echo "<tr>";
	for($j=1;$j<6;$j++)
	{
		echo "<td style='padding-left:25px'>" . $j . " x " . $i . " = " . $i*$j . "</td>";
	}
	echo "</tr>";
}

echo "<tr></tr><tr></tr>";
echo "<br>";
for($i=1;$i<11;$i++)
{
	echo "<tr>";
	for($j=6;$j<11;$j++)
	{
		echo "<td style='padding-left:25px'>" . $j . " x " . $i . " = " . $i*$j . "</td>";
	}

	echo "</tr>";
}
echo "</table>";

echo "<br><br><br>Вывод алфавита: <br>";
for($i=65;$i<91;$i++)
{	
	if ($i==89)
	{
		echo "<span style='color:red'>" . chr($i). "</span>";
	}
	else if((0x208222>>($i&0x1f))&1){
		echo "<span style='color:red'>" . chr($i). "</span>";
	}
	else{
		echo "<span style='color:blue'>" . chr($i). "</span>";
	}
}


echo "<br><br><br>Вывод цифр: <br>";
echo "<center><div style='display: flex; flex-direction: row;flex-wrap: wrap;'>";
for($i=0;$i<=100;$i++)
{	
	if($i%2==0)
		echo "<div style='background-color:blue'>" . $i. "</div>";
	else
		echo "<div style='background-color:red'>" . $i. "</div>";

}
echo "</center></div>";

echo "<br><br><br>Календарь: <br>";
$current_month = date('m');
$days;


switch($current_month){
	case 1: 
	{
		$days = 31;
		break;
	}
	case 2: 
	{
		$days = 28;
		break;
	}
	case 3: 
	{
		$days = 31;
		break;
	}
	case 4: 
	{
		$days = 30;
		break;
	}
	case 5: 
	{
		$days = 31;
		break;
	}
	case 6: 
	{
		$days = 30;
		break;
	}
	case 7: 
	{
		$days = 31;
		break;
	}
	case 8: 
	{
		$days = 31;
		break;
	}
	case 9: 
	{
		$days = 30;
		break;
	}
	case 10: 
	{
		$days = 31;
		break;
	}
	case 11: 
	{
		$days = 30;
		break;
	}
	case 12: 
	{
		$days = 31;
		break;
	}
}

echo "<center><table>";

for($i=1, $k=0;$i<=$days;$i++,$k++)
{
	if($k==0)
	{	
		echo "<tr>";
	}
	if($k==7)
	{
		echo "</tr>";
		$k=0;
	}

	echo "<td>".$i. "</td>";
}

echo "</table></center>";

echo "<br><br><br>Шахматная доска: <br>";
echo "<center><table style='border: 1px solid black; padding:0px'>";
for($i=0; $i < 8; $i++)
{
	echo "<tr>";
	for($j=0; $j < 8; $j++)
	{
		if($i % 2 == 0){
			if($j % 2 == 0)
			{
				echo '<td style="background-color: white; width: 15px; height:15px"></td>';
			} else 
			{
				echo '<td style="background-color: black; width: 15px; height:15px"></td>'; 
			}
		} else {
			if($j % 2 == 0)
			{
				echo '<td style="background-color: black; width: 15px; height:15px"></td>';
			} else 
			{
				echo '<td style="background-color: white; width: 15px; height:15px"></td>'; 
			} 
		}
	}
	echo "</tr>";
}
echo "</center></table>"

?>