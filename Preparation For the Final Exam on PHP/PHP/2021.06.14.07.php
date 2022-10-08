<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../css/2021.06.14.01.css">
    <title>Edit Route Form</title>
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
            $code_route = $_POST['code_route'];

            $sql = "SELECT * FROM route WHERE code_route = " . $code_route;
            $result = $conn->query($sql);
        }
        if ($result->num_rows > 0) {

            while ($row = $result->fetch_assoc()) {

                echo "
                <form action=\"../PHP/2021.06.14.08.php\" method=\"POST\">
                <p>
                <label for=\"code_route\">Code Route</label>
                <input type=\"text\" name=\"code_route\" value=" . $row["code_route"] . ">
                </p>

                <p>
                    <label for=\"class\">Class</label>
                    <input type=\"text\" name=\"class\" value=" . $row["class"] . ">
                </p>
    
                <p>
                    <label for=\"destination\">Destination</label>
                    <input type=\"text\" name=\"destination\" value=" . $row["destination"] . ">
                </p>
    
                <p>
                    <label for=\"price\">Price</label>
                    <input type=\"text\" name=\"price\" value=" . $row["price"] . ">
                </p>
    
                <p>
                    <label for=\"passenger_code\">Passenger Code</label>
                    <input type=\"text\" name=\"passenger_code\" value=" . $row["passenger_code"] . ">
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