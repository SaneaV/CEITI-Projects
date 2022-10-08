<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <link rel="icon" href="https://freepngimg.com/thumb/car/3-2-car-free-download-png.png">
    <title>Update Producator PHP</title>
</head>

<body>

    <div class="mainDiv">

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "automobile";

        $conn = new mysqli($servername, $username, $password, $DBname);

        $cod_producator = $_POST['cod_producator'];
        $an_lansare = $_POST['an_lansare'];
        $denumire = $_POST['denumire'];
        $telefon = $_POST['telefon'];

        $sql = "UPDATE producator SET an_lansare = '" . $an_lansare . "', denumire = '" . $denumire . "', telefon = '" . $telefon . "' WHERE cod_producator = " . $cod_producator;

        if ($conn->query($sql) === TRUE) {
            echo "Producator was succesfully updated<br>";
            echo "<a href=\"../html/2021.06.14.01.html\"> <p>Back to home page</p></a>";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();
        ?>

    </div>

</body>

</html>