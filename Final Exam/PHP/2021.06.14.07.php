<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <link rel="icon" href="https://freepngimg.com/thumb/car/3-2-car-free-download-png.png">
    <title>Edit Route Form</title>
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
            $cod_producator = $_POST['cod_producator'];

            $sql = "SELECT * FROM producator WHERE cod_producator = " . $cod_producator;
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            while ($row = $result->fetch_assoc()) {

                echo "
                <form action=\"../PHP/2021.06.14.08.php\" method=\"POST\">
                <p>
                <label for=\"cod_producator\">cod_producator</label>
                <input type=\"text\" name=\"cod_producator\" value=" . $row["cod_producator"] . ">
                </p>

                <p>
                    <label for=\"an_lansare\">an_lansare</label>
                    <input type=\"text\" name=\"an_lansare\" value=" . $row["an_lansare"] . ">
                </p>
    
                <p>
                    <label for=\"denumire\">denumire</label>
                    <input type=\"text\" name=\"denumire\" value=" . $row["denumire"] . ">
                </p>
    
                <p>
                    <label for=\"price\">telefon</label>
                    <input type=\"text\" name=\"telefon\" value=" . $row["telefon"] . ">
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