<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../CSS/2021.05.03.03.css">
    <title>Result of Search</title>
</head>

<body>

    <div class="mainDiv">
        <?php

        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "library";

        $conn = new mysqli($servername, $username, $password, $DBname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } else {
            $title = $_GET["title"];
            $autor = $_GET["author"];
            $price = $_GET["price"];

            $sql = "SELECT * FROM elib WHERE title = '" . $title . "'AND author = '" . $autor . "' AND price <= " . $price . "";
            $result = $conn->query($sql);

        }
        if ($result !== false && $result->num_rows > 0) {

            echo "<table>";
            echo "<tr><th> ID </th><th> Название  </th><th> Автор </th><th>  Год </th><th>  Издательство </th><th>  Описание </th><th>  Цена </th><th>  Фото </th></tr>";
            while ($row = $result->fetch_assoc()) {

                if (strlen($row["subjects"]) > 1000) {
                    $length = 1000;
                } else {
                    $length = strlen($row["subjects"]);
                }

                echo "<tr><td>" . $row["id"] . "</td>
                <td>" . $row["title"] .  " </td>
                <td> " . $row["author"] . " </td>
                <td>" . $row["year"] . "</td>
                <td>" . $row["publishing"] . "</td>
                <td>" . substr($row["subjects"], 0, $length) . "..." . "</td>
                <td>" . $row["price"] . "$" . "</td>
                <td> <img src=" . '../IMG/' . $row["photo"] . " alt=" . $row["photo"] . "> </td></tr>";
            }
            echo "</table>";
        } else {
            echo "<h3>Ничего не найдено.</h3><br>";
        }

        $conn->close();

        ?>

        <a href="../HTML/2021.03.05.01.html"><button>Вернуться на главную страницу</button></a>
    </div>


</body>

</html>