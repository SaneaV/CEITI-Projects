<?php
//CHANGE INFO
$servername = "localhost";
$username = "root";
$password = "";
$DBname = "user";

$conn = new mysqli($servername, $username, $password, $DBname);

session_start();
$login = $_POST['login'];
$password = $_POST['password'];
$email = $_POST['email'];

$sql = "UPDATE user_data SET login = '" . $login . "', password = '" . $password . "', email = '" . $email . "' WHERE login = '" . $_SESSION['login'] . "' AND password = '" . $_SESSION['password'] . "' AND email = '" . $_SESSION['email'] . "'";

if ($conn->query($sql) === TRUE) {

    $_SESSION['login'] = $login;
    $_SESSION['password'] = $password;
    $_SESSION['email'] = $email;

    echo "Данные были успешно изменены<br>";
    echo "<a href=\"2021.03.12.03 MAIN PAGE AFTER LOGIN.php\"> <p>Вернуться на главную страницу</p></a>";
} else {
    echo "Ошибка: " . $sql . "<br>" . $conn->error;
}

$conn->close();
