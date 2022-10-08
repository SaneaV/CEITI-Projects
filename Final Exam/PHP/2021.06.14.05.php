<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <link rel="icon" href="https://freepngimg.com/thumb/car/3-2-car-free-download-png.png">
    <title>Edit Passenger Form</title>
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
            $cod_automobil = $_POST['cod_automobil'];

            $sql = "SELECT * FROM automobil WHERE cod_automobil = " . $cod_automobil;
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            while ($row = $result->fetch_assoc()) {

                echo "           
            <form action=\"../PHP/2021.06.14.06.php\" method=\"POST\">
            <p>
                <label for=\"cod_automobil\">cod_automobil</label>
                <input type=\"text\" name=\"cod_automobil\" value=" . $row["cod_automobil"] . ">
            </p>

            <p>
                <label for=\"marka\">marka</label>
                <input type=\"text\" name=\"marka\" value=" . $row["marka"] . ">
            </p>

            <p>
            <label for=\"model\">model</label>
            <input type=\"text\" name=\"model\" value=" . $row["model"] . ">
        </p>

            <p>
                <label for=\"nr_usi\">nr_usi</label>
                <input type=\"text\" name=\"nr_usi\" value=" . $row["nr_usi"] . ">
            </p>

            <p>
                <label for=\"pret\">pret</label>
                <input type=\"text\" name=\"pret\" value=" . $row["pret"] . ">
            </p>

            <p>
            <label for=\"cod_producator\">cod_producator</label>
            <input type=\"text\" name=\"cod_producator\" value=" . $row["cod_producator"] . ">
        </p>

            <input type=\"submit\">
        </form>";
            }
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        $conn->close();

        ?>

        <center><a href="../html/2021.06.14.01.html"><button>Back to home page</button></a></center>

    </div>

</body>

</html>