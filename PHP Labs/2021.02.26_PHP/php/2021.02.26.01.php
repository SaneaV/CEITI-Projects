    <!DOCTYPE html>
    <html lang="en">

    <head>
        <meta charset="UTF-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <link rel="stylesheet" href="../css/2021.02.26.01.css">
        <title>Weather</title>
    </head>

    <body>

        <div id="mainBlock">

            <p>Available dates: 26.02.2021 - 05.03.2021</p>

            <div id="dateBlock">
                <form action="../php/2021.02.26.01.php" id="okBox" method="POST">
                    <label for="dateBox">Date: </label>
                    <input type="date" name="dateBox" value="<?php echo date('Y-m-d'); ?>">
                    <input type="submit" value="OK">
                </form>
            </div>

            <div id="forecastBlock">

                <?php
                $new_date = date('Y-m-d', strtotime($_POST['dateBox']));

                $servername = "localhost";
                $username = "root";
                $password = "";
                $DBname = "weather";

                $conn = new mysqli($servername, $username, $password, $DBname);

                if ($conn->connect_error) {
                    die("Connection failed: " . $conn->connect_error);
                } else {
                    $sql = "SELECT * FROM weather_forecast WHERE Date_W = '" . $new_date . "'";
                    $result = $conn->query($sql);
                }
                if ($result->num_rows > 0) {
                    echo '<div>';
                    $row = $result->fetch_assoc();
                    echo "<p>" . $row["Date_W"] . "</p>";
                    echo "<p>Temperature: " . $row["Temperature"] . " C&#176;</p>";
                    echo "<p>Wind: " . $row["Wind"] . " m/s NE</p>";
                    echo '</div>';

                    echo '<div>';
                    if ($row["Shortly"] == "sun")
                        echo '<img src="../img/sunny.png" alt="sun" style="width: 100px">';

                    if ($row["Shortly"] == "cls")
                        echo '<img src="../img/cloud.png" alt="cloud" style="width: 100px">';

                    if ($row["Shortly"] == "ran")
                        echo '<img src="../img/drop.png" alt="rain" style="width: 100px">';

                    if ($row["Shortly"] == "snw")
                        echo '<img src="../img/snowflake.png" alt="snow" style="width: 100px">';

                    if ($row["Shortly"] == "wnd")
                        echo '<img src="../img/wind.png" alt="wind" style="width: 100px">';
                    echo '</div>';
                } else {
                    echo "Прогноз ещё не готов!";
                }

                $conn->close();
                ?>
            </div>

        </div>

    </body>

    </html>