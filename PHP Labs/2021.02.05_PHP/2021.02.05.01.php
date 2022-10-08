<?php
echo "<div style='text-align:center; width:60%; margin:0 auto; border:1px solid black;box-shadow: 0 0 10px rgba(0,0,0,0.5);    padding: 10px;'>";

date_default_timezone_set("Europe/Chisinau");
set_time_limit(600);

echo "<b>First Task</b><br>";
echo "Date: ".mktime(0,0,0,3,1,2025);

echo "<br><br><b>Second Task</b><br>";
echo "The hours difference between \"7:23:48 this day\" and Now is: ";
echo intval(abs((time() - mktime(7,23,48))/3600))." fix hour";

echo "<br><br><b>Third Task</b><br>";
$month = array("January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December");
echo "Now is ".$month[date("n",time())-1];	


echo "<br><br><b>Fourth Task</b><br>";
$date = '31.12.2025';
$explodedDate = explode(".", $date);
$timeStampDate = mktime(0,0,0,$explodedDate[1], $explodedDate[0],$explodedDate[2]);
$week = array("Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday");
echo "The day of week of date ".$date." is ".$week[date("w", $timeStampDate)];

echo "<br><br><b>Fifth Task</b><br>";
$isThirteen = array();

for($i=1;$i<=12;$i++)
{
	if(date('w',mktime(0,0,0,$i,13,date('Y')))==5)
	{
		array_push($isThirteen, "13.".$i.".".date('Y'));
	}
}

echo "The dates of Friday 13 in this year: ";
print_r($isThirteen);

echo "<br><br><b>First Task</b><br>";
$array = array();
$checkedArray = array();

for($i=0;$i<20;$i++)
{
	array_push($array, rand(-20,20));

	if(isNumberInRange($array[$i])) 
		$checkedArray[] = $array[$i];
}

echo "Initial array: ";
echo printArray($array, count($array));
echo "Checked array: ";
echo printArray($checkedArray, count($checkedArray));

function printArray($arr, $size){
	for($i=0;$i<$size;$i++)
		echo $arr[$i].' ';
	echo "<br>";
}

function isNumberInRange($i){
	if($i<10 && $i>0)
		return 1;
}

echo "<br><b>Second Task</b><br>";
$numbers = array(1, 2, 3, 4, 5);

for($i=0;$i<count($numbers);$i++)
{
	echo $numbers[$i].' is even -';
	if(isEven($numbers[$i])) echo ' true<br>';
	else echo ' false<br>';
}

function isEven($i){
	if($i%2==0)
		return 1;
	return 0;
}

echo "<br><b>Third Task</b><br>";
$a = 10;
$b = 20;
echo "Numbers: ".$a." and ".$b."<br>";
getCommonDivisors($a,$b);

function getCommonDivisors($a,$b){

	$divisorsA = giveDivisorsArray($a);
	$divisorsB = giveDivisorsArray($b);

	$tempArray = array_values(array_intersect($divisorsA, $divisorsB));
	echo "Common Divivsors: ";
	printArray($tempArray, count($tempArray));
}

function giveDivisorsArray($temp){
	$tempArray = array();
	for ($i = 1; $i < $temp; $i++)
	{
		if($temp%$i==0) $tempArray[] = $i;
	}

	return $tempArray;
}

echo "<br><b>Fourth Task</b><br>";
for($i=1;$i<10000;$i++){
	$currentDivs = sumDiv($i);

	$resultDivs = sumDiv($currentDivs);


	if($i == $resultDivs && $currentDivs != $resultDivs){
		echo $i." - ".$currentDivs."</br>";
	}	
}

function sumDiv($num) {
	$result = 1;
	$sqrt = sqrt($num);

	if($num <= 1) {
		return 0;
	}
	for ($i = 2; $i * $i <= $num; $i++) {
		if ($num % $i == 0){
			$result += $i + $num / $i;
		}
	}
	if (floor($sqrt) == $sqrt) {
		$result += $sqrt; 
	}
	return $result;
}   

echo "<br><b>Fifth Task</b><br>";

function fillArray(){
	$tempArray = array();
	for($i=0;$i<10;$i++)
	{
		$tempArray[] = rand(0, 100);
	}

	return $tempArray;
}

print_r(fillArray());

echo "<br><br><b>Fifth Task</b><br>";

function Dividers($temp){
	$tempArray = array();
	echo("Number: ".$temp."<br>");
	for ($i = 1; $i <= $temp; $i++)
	{
		if($temp%$i==0) $tempArray[] = $i;
	}

	return $tempArray;
}

print_r(Dividers(rand(10,100)));


?>