<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <title>Update Passenger PHP</title>
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
        $name = $_POST['name'];
        $phone = $_POST['phone'];
        $surname = $_POST['surname'];

        $sql = "UPDATE passenger SET name = '" . $name . "', phone = '" . $phone . "', surname = '" . $surname . "' WHERE passenger_code = " . $passenger_code;

        if ($conn->query($sql) === TRUE) {
            echo "Passenger was succesfully updated<br>";
            echo "<a href=\"../html/2021.06.14.01.html\"> <p>Back to home page</p></a>";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();
        ?>

    </div>

</body>

</html>