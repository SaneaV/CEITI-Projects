<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <title>Update Route PHP</title>
</head>

<body>

    <div class="mainDiv">

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "airport";

        $conn = new mysqli($servername, $username, $password, $DBname);

        $passenger_code = $_POST['passenger_code'];
        $class = $_POST['class'];
        $price = $_POST['price'];
        $destination = $_POST['destination'];
        $code_route = $_POST['code_route'];

        $sql = "UPDATE route SET passenger_code = '" . $passenger_code . "', class = '" . $class . "', price = '" . $price . "', destination = '" . $destination . "' WHERE code_route = " . $code_route;

        if ($conn->query($sql) === TRUE) {
            echo "Route was succesfully updated<br>";
            echo "<a href=\"../html/2021.06.14.01.html\"> <p>Back to home page</p></a>";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();
        ?>

    </div>

</body>

</html>