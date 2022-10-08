<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <title>Task 2</title>
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
            $class = $_POST['class'];
            $destination = $_POST['destination'];

            $sql = "SELECT name, surname, phone, class, destination, price
            FROM route INNER JOIN passenger ON route.passenger_code = passenger.passenger_code
            WHERE destination LIKE '" . $destination . "' AND class LIKE '" . $class . "'";
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            echo "<table>";
            echo "<tr><th> name </th><th> surname </th><th> phone </th><th> Class </th><th> Destination </th><th> Price </th></tr>";
            while ($row = $result->fetch_assoc()) {

                echo "<tr><td>" . $row["name"] . "</td>
                <td>" . $row["surname"] .  " </td>
                <td>" . $row["phone"] .  " </td>
                <td>" . $row["class"] .  " </td>
                <td> " . $row["destination"] . " </td>
                <td>" . $row["price"] . "</td></tr>";
            }
            echo "</table>";
        } else {
            echo "User are not found <br>" . $conn->error;
        }

        $conn->close();

        ?>

        <a href="../html/2021.06.14.01.html"><button>Back to home page</button></a>

    </div>

</body>

</html>