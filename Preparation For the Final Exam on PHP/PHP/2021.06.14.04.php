<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <title>Add Route PHP</title>
</head>

<body>

    <div class="mainDiv">

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "airport";

        $conn = new mysqli($servername, $username, $password, $DBname);

        $class = $_POST['class'];
        $destination = $_POST['destination'];
        $price = $_POST['price'];
        $passengerCode = $_POST['passenger_code'];

        $sql = "INSERT INTO route VALUES (NULL,'" . $class . "', '" . $destination . "', '" . $price . "', '" . $passengerCode . "')";

        if ($conn->query($sql) === TRUE) {
            echo "Route was succesfully added<br>";
            echo "<a href=\"../html/2021.06.14.01.html\"> <p>Back to home page</p></a>";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();
        ?>

    </div>

</body>

</html>