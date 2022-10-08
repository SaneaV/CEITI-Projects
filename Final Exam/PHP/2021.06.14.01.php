<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <link rel="icon" href="https://freepngimg.com/thumb/car/3-2-car-free-download-png.png">
    <title>Show Car</title>
</head>

<body>

    <div class="mainDiv">

    <h1>Manufacter's List</h1>

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "automobile";

        $conn = new mysqli($servername, $username, $password, $DBname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } else {
            $sql = "SELECT * FROM producator";
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            echo "<table>";
            echo "<tr><th> Manufacter's code </th><th> Year of establishment </th><th> Name </th><th> Phone </th></tr>";
            while ($row = $result->fetch_assoc()) {

                echo "<tr><td>" . $row["cod_producator"] . "</td>
                <td>" . $row["an_lansare"] .  " </td>
                <td>" . $row["denumire"] . "</td>
                <td>" . $row["telefon"] . "</td></tr>";
            }
            echo "</table>";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();

        ?>

        <a href="../html/2021.06.14.01.html"><button>Back to home page</button></a>

    </div>

</body>

</html>