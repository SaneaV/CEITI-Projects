<?php
$servername = "localhost";
$username = "root";
$password = "";
$DBname = "user";

$conn = new mysqli($servername, $username, $password, $DBname);

$login = $_POST['login'];
$password = $_POST['password'];
$email = $_POST['email'];

$sql = "SELECT COUNT(*) as `result` FROM user_data WHERE login = '" . $login . "' AND password = '" . $password . "'";
$result = $conn->query($sql);
$row = $result->fetch_assoc();

if ($row["result"] == 0) {

    $sql = "INSERT INTO user_data VALUES (NULL,'" . $login . "', '" . $password . "', '" . $email . "')";

    if ($conn->query($sql) === TRUE) {
        session_start();
        $_SESSION['login'] = $login;
        $_SESSION['password'] = $password;
        $_SESSION['email'] = $email;

        echo "Регистрация прошла успешно<br>";
        echo "<a href=\"2021.03.12.03 MAIN PAGE AFTER LOGIN.php\"> <p>Вернуться на главную страницу</p></a>";
    } else {
        echo "Ошибка: " . $sql . "<br>" . $conn->error;
    }
} else {
    echo "Ошибка: Аккаунт с таким именем или почтой уже существует";

    echo "<a href=\"../HTML/2021.03.12.01 HOME PAGE.html\"> <p>Вернуться на главную страницу</p></a>";
}

$conn->close();
