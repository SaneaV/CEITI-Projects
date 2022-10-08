<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <link rel="icon" href="https://freepngimg.com/thumb/car/3-2-car-free-download-png.png">
    <title>Task 2</title>
</head>

<body>

    <div class="mainDiv">

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "automobile";

        $conn = new mysqli($servername, $username, $password, $DBname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } else {

            $sql = "SELECT *
            FROM automobil
            WHERE marka LIKE 'BMW' AND nr_usi LIKE '2'";
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            echo "<table>";
            echo "<tr><th> Car's code </th><th> Mark  </th><th> Model </th><th>  Number of doors </th><th>  Price </th><th>  Manufacter's code </th></tr>";
            while ($row = $result->fetch_assoc()) {

                echo "<tr><td>" . $row["cod_automobil"] . "</td>
                <td>" . $row["marka"] .  " </td>
                <td> " . $row["model"] . " </td>
                <td>" . $row["nr_usi"] . "</td>
                <td> " . $row["pret"] . " </td>
                <td> " . $row["cod_producator"] . " </td></tr>";
            }
            echo "</table>";
        } else {
            echo "No such car <br>" . $conn->error;
        }

        $conn->close();

        ?>

        <a href="../html/2021.06.14.01.html"><button>Back to home page</button></a>

    </div>

</body>

</html>