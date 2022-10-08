<?php
echo "<b>Задача №1</b>";
$a = 3;
echo "<br>" . $a;

echo "<b><br><br>Задача №2</b>";
$a = 10;
$b = 2;
echo "<br> Сумма: " . $a+$b;
echo "<br> Разность: " . $a-$b;
echo "<br> Произведение: " . $a*$b;
echo "<br> Частное: " . $a/$b;

echo "<b><br><br>Задача №3</b>";
$c = 15;
$d = 2;
$result = $c + $d;
echo "<br>" . $result;

echo "<b><br><br>Задача №4</b>";
$a = 10;
$b = 2;
$c = 5;
echo "<br>" . $a+$b+$c;

echo "<b><br><br>Задача №5</b>";
$a = 17;
$b = 10;
$c = $a - $b;
$d = 7;
$result = $c + $d;
echo "<br>" . $result;

echo "<b><br><br>Задача №6</b>";
$seconds = 60;
$secondsHour = $seconds * 60;
$secondsDay = $secondsHour * 24;
$secondsMonth = $secondsDay * 30;
echo "<br>Секунд в часе: " . $secondsHour;
echo "<br>Секунд в дне: " . $secondsDay;
echo "<br>Секунд в месяце: " . $secondsMonth;

echo "<b><br><br>Задача №7</b>";
$hour = 8;
$minute = 30;
$second = 35;
echo "<br>".$hour.":".$minute.":".$second;

echo "<b><br><br>Задача №8</b>";
$a = 10;
$b = 20;
echo "<br>Сумма: ".$a+$b;
echo "<br>Произведение: ".$a*$b;
echo "<br>Сумма квадратов чисел: ".$a*$a+$b*$b;

echo "<b><br><br>Задача №9</b>";
$a = 5;
$b = 7;
$c = 9;
$mediumArithmetic = ($a+$b+$c)/3;
echo "<br>Среднее арифметическое: ". $mediumArithmetic;

echo "<b><br><br>Задача №10</b>";
$x = 5;
$z = 7;
$y = 9;
$result = pow(($x+1),4) - 2 * ($z - 2 * pow($x, 2) + pow($y,2)) + sqrt(sin(abs($y)));
echo "<br>Результат: ".$result;

echo "<b><br><br>Задача №11</b>";
$a = 10;
$b = 20;
$c = 30;
echo "<br>(a+b)/c = ".($a+$b)/$c;
echo "<br>(a+c)/b = ".($a+$c)/$b;
echo "<br>(c+b)/a = ".($c+$b)/$a;

echo "<b><br><br>Задача №12</b>";
$a = 10;
echo "<br> a Mod 3 = ".$a%3;
echo "<br> a Mod 5 = ".$a%5;

echo "<b><br><br>Задача №13</b>";
$a = 10;
echo "<br> a + 30% = ".$a*0.3 + $a;
echo "<br> a + 120% = ".$a*1.2 + $a;

echo "<b><br><br>Задача №14</b>";
$a = 10;
$b = 20;
echo "<br>40% от a + 84% от a = ".$a*0.4 + $b*0.84;

echo "<b><br><br>Задача №15</b>";
$a = 123;
$firstNumber = $a%10;
$secondNumber = $a/10%10;
$thirdNumber = $a/100%10;
echo "<br>Сумма цифр, числа 123 = ".$firstNumber + $secondNumber + $thirdNumber;

echo "<b><br><br>Задача №16</b>";
$a = 123;
$firstNumber = $a%10;
$secondNumber = 0;
$thirdNumber = $a/100%10;
$result = $firstNumber.$secondNumber.$thirdNumber;
echo "<br>Полученное число = ".$result;
?>