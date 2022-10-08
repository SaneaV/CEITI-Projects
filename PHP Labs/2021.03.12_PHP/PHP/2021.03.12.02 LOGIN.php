<?php
$servername = "localhost";
$username = "root";
$password = "";
$DBname = "user";

$conn = new mysqli($servername, $username, $password, $DBname);

$login = $_GET['login'];
$password = $_GET['password'];

$sql = "SELECT COUNT(*) as `result` FROM user_data WHERE login = '" . $login . "' AND password = '" . $password . "'";
$result = $conn->query($sql);
$row = $result->fetch_assoc();  

if ($row["result"]==1) {
    session_start();
    $_SESSION['login'] = $login;
    $_SESSION['password'] = $password;

    $sql = "SELECT email FROM user_data WHERE login = '" . $login . "' AND password = '" . $password . "'";
    $result = $conn->query($sql);
    $row = $result->fetch_assoc();
    $_SESSION['email'] = $row["email"];

    echo "Вы успешно зашли в свой аккаунт<br>";
    echo "<a href=\"../PHP/2021.03.12.03 MAIN PAGE AFTER LOGIN.php\"> <p>Вернуться на главную страницу</p></a>";
} else {
    echo "Ошибка: Аккаунт не найден";

    echo "<a href=\"../HTML/2021.03.12.01 HOME PAGE.html\"> <p>Вернуться на главную страницу</p></a>";
}

$conn->close();
