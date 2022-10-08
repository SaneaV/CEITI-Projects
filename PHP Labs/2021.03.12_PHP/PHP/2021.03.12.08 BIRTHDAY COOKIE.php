<?php

$date_timestamp = strtotime($_POST['date']);
$day = date("d", $date_timestamp);
$month = date("m", $date_timestamp);
$year = date("Y", $date_timestamp);

setcookie("day", $day);
setcookie("month", $month);
setcookie("year", $year);

echo "Вы добавили свою дату рождения<br>";
echo "<a href=\"../PHP/2021.03.12.03 MAIN PAGE AFTER LOGIN.php\"> <p>Вернуться на главную страницу</p></a>";

?>