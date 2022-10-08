<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <link rel="icon" href="https://freepngimg.com/thumb/car/3-2-car-free-download-png.png">
    <title>Add Automobil PHP</title>
</head>

<body>

    <div class="mainDiv">

        <?php
        $servername = "localhost";
        $username = "root";
        $password = "";
        $DBname = "automobile";

        $conn = new mysqli($servername, $username, $password, $DBname);

        $marka = $_POST['marka'];
        $model = $_POST['model'];
        $nr_usi = $_POST['nr_usi'];
        $pret = $_POST['pret'];
        $cod_producator = $_POST['cod_producator'];

        $sql = "INSERT INTO automobil VALUES (NULL,'" . $marka . "', '" . $model . "', '" . $nr_usi . "', '" . $pret . "', '" . $cod_producator . "')";

        if ($conn->query($sql) === TRUE) {
            echo "Automobil was succesfully added<br>";
            echo "<a href=\"../html/2021.06.14.01.html\"> <p>Back to home page</p></a>";
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();
        ?>

    </div>

</body>

</html>