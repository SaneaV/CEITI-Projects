<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../CSS/2021.05.03.03.css">
    <title>Result of Adding</title>
</head>

<body>

    <div class="mainDiv">
        <?php

        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "library";

        $conn = new mysqli($servername, $username, $password, $DBname);

        $uploadDir = "../IMG/";
        $tmp = basename($_FILES['photo']['name']);
        $uploadFile = $uploadDir . $tmp;
        copy($_FILES['photo']['tmp_name'], $uploadFile);

        $title = $_POST['title'];
        $author = $_POST['author'];
        $year = $_POST['year'];
        $publishing = $_POST['publishing'];
        $subjects = $_POST['subjects'];
        $price = $_POST['price'];
        $photo = basename($_FILES['photo']['name']);

        $sql = "INSERT INTO eLib VALUES (NULL," . $title . "', '" . $author . "', '" . $year . "','" . $publishing . "','" . $subjects . "','" . $price . "','" . $photo . "')";

        if ($conn->query($sql) === TRUE) {
            echo "Книга успешно добавленна!<br>";
        } else {
            echo "Ошибка: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();


        ?>

        <a href="../HTML/2021.03.05.01.html"><button>Вернуться на главную страницу</button></a>
    </div>


</body>

</html>