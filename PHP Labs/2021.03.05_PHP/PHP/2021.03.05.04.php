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

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } else {
            $sql = "SELECT `publishing`, SUM(price) AS `Overall_Price`, COUNT(*) AS `Number_Of_Publishing` FROM `elib` GROUP BY `publishing`";
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            echo "<table>";
            echo "<tr><th> Издательство </th><th> Средняя цена  </th></tr>";
            while ($row = $result->fetch_assoc()) {

                echo "<tr><td>" . $row["publishing"] . "</td>
                <td>" . $row["Overall_Price"]/$row["Number_Of_Publishing"] .  " </td></tr>";
            }
            echo "</table>";
        } else {
            echo "Ошибка: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();


        ?>

        <a href="../HTML/2021.03.05.01.html"><button>Вернуться на главную страницу</button></a>
    </div>


</body>

</html>