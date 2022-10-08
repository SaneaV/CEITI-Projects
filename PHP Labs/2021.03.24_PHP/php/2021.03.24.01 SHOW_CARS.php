<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.03.24 SHOW_CARS.css">
    <title>Cars</title>
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
            $sql = "SELECT * FROM autopark";
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            echo "<table>";
            echo "<tr><th> ID </th><th> Марка  </th><th> Модель </th><th>  Год выпуска </th><th>  Объём двигателя </th><th>  Топливо </th><th>  КП </th><th>  Цена </th><th>  Фото </th></tr>";
            while ($row = $result->fetch_assoc()) {

                echo "<tr><td>" . $row["id"] . "</td>
                <td>" . $row["mark"] .  " </td>
                <td> " . $row["model"] . " </td>
                <td>" . $row["year"] . "</td>
                <td>" . $row["engine_capacity"] . "</td>
                <td>" . $row["fuel"] . "</td>
                <td>" . $row["transmission"] . "</td>
                <td>" . $row["price"] . "$" . "</td>
                <td> <img src=" . '../IMG/' . $row["photo"] . " alt=" . $row["photo"] . "> </td></tr>";
            }
            echo "</table>";
        } else {
            echo "Ошибка: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();

        ?>

        <a href="../html/2021.03.24.01 HOME_PAGE.html"><button>Вернуться на главную страницу</button></a>
    </div>

</body>

</html>