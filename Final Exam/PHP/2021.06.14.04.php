<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <link rel="icon" href="https://freepngimg.com/thumb/car/3-2-car-free-download-png.png">
    <title>Add Producator PHP</title>
</head>

<body>

    <div class="mainDiv">

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "automobile";

        $conn = new mysqli($servername, $username, $password, $DBname);

        $an_lansare = $_POST['an_lansare'];
        $denumire = $_POST['denumire'];
        $telefon = $_POST['telefon'];

        $sql = "INSERT INTO producator VALUES (NULL,'" . $an_lansare . "', '" . $denumire . "', '" . $telefon . "')";

        if ($conn->query($sql) === TRUE) {
            echo "Manufacter was succesfully added<br>";
            echo "<a href=\"../html/2021.06.14.01.html\"> <p>Back to home page</p></a>";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();
        ?>

    </div>

</body>

</html>