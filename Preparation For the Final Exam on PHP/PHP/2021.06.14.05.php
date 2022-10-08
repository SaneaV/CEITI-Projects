<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <title>Edit Passenger Form</title>
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
            $passenger_code = $_POST['passenger_code'];

            $sql = "SELECT * FROM passenger WHERE passenger_code = " . $passenger_code;
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            while ($row = $result->fetch_assoc()) {

                echo "           
            <form action=\"../PHP/2021.06.14.06.php\" method=\"POST\">
            <p>
                <label for=\"passenger_code\">Passenger Code</label>
                <input type=\"text\" name=\"passenger_code\" value=" . $row["passenger_code"] . ">
            </p>

            <p>
                <label for=\"name\">Name</label>
                <input type=\"text\" name=\"name\" value=" . $row["name"] . ">
            </p>

            <p>
                <label for=\"phone\">Phone</label>
                <input type=\"text\" name=\"phone\" value=" . $row["phone"] . ">
            </p>

            <p>
                <label for=\"surname\">Surname</label>
                <input type=\"text\" name=\"surname\" value=" . $row["surname"] . ">
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