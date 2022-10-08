<?php
echo "<div style='text-align:center; width:60%; margin:0 auto; border:1px solid black;box-shadow: 0 0 10px rgba(0,0,0,0.5);    padding: 10px;'>";
/*============================================*/
$file = fopen("First.txt","w");
$line = "";
$k = 1;
for($i=1;$i<=999;$i++, $k++){
	$line .= $i . " ";

	if($i%3==0)
	{
		$line .= "\n";
		fputs($file, $line);
		$k = 0;
		$line = "";
	}
}
fclose($file);
echo "<b>First done!</b><br><br>";

/*============================================*/
$file = fopen("Second.txt","w");
for($i=65;$i<=90;$i++)
{
	for($j=0;$j<10;$j++)
	{
		$line .= chr($i);
	}
	$line.="\n";
	fputs($file, $line);
	$line = "";
}
fclose($file);
echo "<b>Second done!</b><br><br>";

/*============================================*/
$file_1 = fopen("Third_1.txt","r");
$file_2 = fopen("Third_2.txt","w");
while(!feof($file_1)){
	$line = fgets($file_1);
	$line = aTOc($line);
	fputs($file_2,$line);
}

function aTOc($string){
	for($i=0;$i<strlen($string);$i++)
	{
		if($string[$i]=='c')
			$string[$i] = 'a';
	}

	return $string;
}
fclose($file_1);
fclose($file_2);
echo "<b>Third done!</b><br><br>";

/*============================================*/

$file_1 = fopen("Fourth_1.txt","r");
$file_2 = fopen("Fourth_2.txt","w");
$min = 255;
$stringMin = "";

while(!feof($file_1)){

	$line = fgets($file_1);
	if($min>findMin($line, $min))
	{
		$stringMin = "";
		$min = findMin($line, $min);
	}

	if(strlen($line)==$min)
		$stringMin.=$line;
}

fputs($file_2, $stringMin);
echo $stringMin;

function findMin($string, $min){
	
	if(strlen($string)<$min) return strlen($string);
	return $min;
}

fclose($file_1);
fclose($file_2);
echo "<b><br><br>Fourth done!</b><br><br>";

/*============================================*/
$string = "";

for($i=1;$i<=20;$i++)
{
	for($j=1;$j<=20;$j++)
	{
		$string .= $i." * ".$j." = ".$i*$j."\n";
	}

	$string.="\n";
}

$file = fopen("Fifth.txt","w");
fputs($file, $string);
fclose($file);
echo "<b>Fifth done!</b><br><br>";
/*============================================*/

$file = fopen("Sixth_1.txt","r");

$minAge = 200;
$maxAge = 0;

$minHeight = 200;
$maxHeight = 0;

$minWeight = 200;
$maxWeight = 0;

echo "<table style='margin:0 auto'>";
while(!feof($file)){
	$line = fgets($file);
	list($name, $surname, $age, $height, $weight) = explode(" ", $line);

	if($minAge>$age) $minAge = $age;
	if($maxAge<$age) $maxAge = $age;
	if($minHeight>$height) $minHeight = $height;
	if($maxHeight<$height) $maxHeight = $height;
	if($minWeight>$weight) $minWeight = $weight;
	if($maxWeight<$weight) $maxWeight = $weight;

	echo "<tr>";
	echo "<td>".$name."</td><td>".$surname."</td><td>".$age."</td><td>".$weight."</td><td>".$height."</td>";
	echo "</tr>";
}
echo "</table>";
fclose($file);

$file = fopen("Sixth.txt","w");
fputs($file, "Минимальный возраст: ".$minAge."\n");
fputs($file, "Максимальный возраст: ".$maxAge."\n");
fputs($file, "Минимальный рост: ".$minHeight."\n");
fputs($file, "Максимальный рост: ".$maxHeight."\n");
fputs($file, "Минимальный вес: ".$minWeight);
fputs($file, "Максимальный вес: ".$maxWeight."\n");

echo "<b><br>Sixth done!</b><br><br>";

?>