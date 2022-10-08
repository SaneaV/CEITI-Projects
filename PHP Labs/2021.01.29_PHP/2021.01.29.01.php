<?php
echo "<div style='text-align:center; width:60%; margin:0 auto; border:1px solid black;box-shadow: 0 0 10px rgba(0,0,0,0.5);    padding: 10px;'>";

echo '<b>TASK №1</b><br>';
$A = array(4, -8, 7, -6, 0, -7, 5);

echo "Start: ";
for($i=0;$i<count($A);$i++)
	echo $A[$i]." ";
echo "<br>Finish: ";

$B = array();

$size = count($A)-1;
for ($i=0; $i<$size; $i++) {
	for ($j=0; $j<$size-$i; $j++) {
		$k = $j+1;
		if ($A[$k] < $A[$j]) {
			$C = $A[$k];
			$A[$k] = $A[$j];
			$A[$j] = $C; 
		}
	}
}

$k=0;
for($i=0;$i<=$size;$i++)
{
	if($A[$i]>=0)
		$B[$k++] = $A[$i];

}
for($i=count($A)-1;$i>=0;$i--)
{
	if($A[$i]<0)
		$B[$k++] = $A[$i];

}

for($i=0;$i<=$size;$i++)
{
	echo $B[$i]." ";
}

echo '<b><br><br>TASK №2</b><br>';

$num = array(14, -2, 3, 14, 3, -2, 5);
$count = array_count_values($num); 
print_r(array_count_values($num));
$unique = count($count);
echo "<br>Uniqal numbers: ".$unique;

echo '<b><br><br>TASK №3</b><br>';

echo "Start: ";
$A = array(-1,2,5,0,2);
for($i=0;$i<count($A);$i++)
	echo $A[$i]." ";
echo "<br>Finish: ";
$sum = array();

for($i=0;$i<count($A);$i++)
{
	if($i>0)
	{	
		$sumRest = 0;
		for($k=0;$k<count($A);$k++)
		{
			if(($k!=$i && $k!=($i-1)))
			{
				$sumRest += $A[$k];
			}
		}
		echo $sumRest." ";
	}

	echo $A[$i]." ";
}

echo '<b><br><br>TASK №4</b><br>';

$array = array(14, -2, 3, 14, 3, -2, 5,-1, 2, 5, 0, 2);
print_r($array);
echo '<br>Element for search: k=8<br>';

$n = count($array);
$k = 8;
$p = -1; 
$min = min($array) - 1;
$tmp = $min;

while ($p < $k - 1) {
	$count = 0;
	for ($i = 0; $i < $n; $i++) {
		if ($tmp == $min) {

			if ($tmp < $array[$i]) {
				$tmp = $array[$i];
				$count = 1;
			}
		} else {

			if ($tmp >= $array[$i] && $array[$i] > $min) {
				if ($tmp == $array[$i]) {
					$count++;
				} else {
					$tmp = $array[$i];
					$count = 1;
				}
			}
		}
	}
	$p += $count;
	$min = $tmp;
}

echo 'k(8) = '.$min;

echo '<b><br><br>TASK №5</b><br>';

$string = "london is the capital of great britain";
$words = explode(" ", $string);
$string = "";

for($i=0;$i<count($words);$i++)
{
	$string .= ucfirst($words[$i]) . " ";
}

echo $string;

echo '<b><br><br>TASK №6</b><br>';

$string = "london is the capital of great britain";
echo 'String: london is the capital of great britain<br>';
echo 'Last 3 symbols = ';
echo substr($string, strlen($string)-3, strlen($string));

echo '<b><br><br>TASK №7</b><br>';

$string = "london is the capital of great britain.png";
echo 'String: london is the capital of great britain.png<br>';
echo 'The string ends with ".png" or ".jpg"? ';
$tmpString = substr($string, strlen($string)-4, strlen($string));

switch($tmpString){
	case ".png":{
		echo "Yes";
		break;
	}
	case ".jpg":{
		echo "Yes";
		break;
	}
	default:{
		echo "No";
	}
}

echo '<b><br><br>TASK №7</b><br>';

$string = "1a2b3c4b5d6e7f8g9h0";
$tmpString = "";

for($i=0;$i<strlen($string);$i++)
{
	if(!is_numeric($string[$i]))
		$tmpString .= $string[$i];
}

echo $tmpString;

echo '<b><br><br>TASK №8</b><br>';

$array = array('html', 'css', 'php');
$comma_separated = implode(",", $array);

echo $comma_separated;

echo "</div>"
?>