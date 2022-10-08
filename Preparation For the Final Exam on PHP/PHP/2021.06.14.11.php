<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <title>Task 3</title>
</head>

<body>

    <div class="mainDiv">

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "airport";

        $conn = new mysqli($servername, $username, $password, $DBname);

        if ($conn->connect_error) {
            die("Connection failed: " . $conn->connect_error);
        } else {
            $sql = "select destination, SUM(price) as total_sum, GROUP_CONCAT(DISTINCT CONCAT(name,' ', surname)) as passengers
            FROM route INNER JOIN passenger ON route.passenger_code = passenger.passenger_code
            group by destination";
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            echo "<table>";
            echo "<tr><th> destination </th><th> total_sum </th><th> passengers </th></tr>";
            while ($row = $result->fetch_assoc()) {

                echo "<tr><td>" . $row["destination"] . "</td>
                <td>" . $row["total_sum"] .  " </td>
                <td>" . $row["passengers"] .  " </td></tr>";
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