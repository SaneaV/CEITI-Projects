<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <title>Show Routes</title>
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
            $sql = "SELECT * FROM route";
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            echo "<table>";
            echo "<tr><th> CodeRoute </th><th> Class </th><th> Destination </th><th> Price </th><th> PassengerCode </th></tr>";
            while ($row = $result->fetch_assoc()) {

                echo "<tr><td>" . $row["code_route"] . "</td>
                <td>" . $row["class"] .  " </td>
                <td> " . $row["destination"] . " </td>
                <td>" . $row["price"] . "</td>
                <td>" . $row["passenger_code"] . "</td></tr>";
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