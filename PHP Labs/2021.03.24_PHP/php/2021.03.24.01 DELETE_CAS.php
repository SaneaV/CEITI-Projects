<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.03.24 DEFAULT.css">
    <title>Delete a Car</title>
</head>

<body>

    <div class="mainDiv">
        <?php

        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "cars";

        $conn = new mysqli($servername, $username, $password, $DBname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } else {
            $mark = $_GET["mark"];
            $model = $_GET["model"];
            $year = $_GET["year"];

            $sql = "DELETE FROM AUTOPARK WHERE mark = '" . $mark . "'AND model = '" . $model . "' AND year = " . $year . "";
        }
        if ($conn->query($sql)==TRUE && $conn->affected_rows > 0) {
            echo "<h3>Машина была удалена!</h3><br>";
        } else {
            echo "<h3>Ничего не найдено.</h3><br>";
        }

        $conn->close();

        ?>

        <a href="../html/2021.03.24.01 HOME_PAGE.html"><button>Вернуться на главную страницу</button></a>
    </div>


</body>

</html>