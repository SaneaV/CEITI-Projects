<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <link rel="icon" href="https://freepngimg.com/thumb/car/3-2-car-free-download-png.png">
    <title>Task 3</title>
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
            $sql = "select denumire, SUM(pret) as total_sum, GROUP_CONCAT(DISTINCT CONCAT(model)) as cars
            FROM automobil INNER JOIN producator ON automobil.cod_producator = producator.cod_producator
            group by denumire";
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            echo "<table>";
            echo "<tr><th> Name </th><th> Overall Sum </th><th> List of cars </th></tr>";
            while ($row = $result->fetch_assoc()) {

                echo "<tr><td>" . $row["denumire"] . "</td>
                <td>" . $row["total_sum"] .  " </td>
                <td>" . $row["cars"] .  " </td></tr>";
            }
            echo "</table>";
        } else {
            echo "Nothing to display" . $conn->error;
        }

        $conn->close();

        ?>

        <a href="../html/2021.06.14.01.html"><button>Back to home page</button></a>

    </div>

</body>

</html>