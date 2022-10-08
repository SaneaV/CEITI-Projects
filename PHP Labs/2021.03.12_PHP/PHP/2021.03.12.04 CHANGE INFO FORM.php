<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../CSS/2021.03.12.02.css">
    <title>Change Info</title>
</head>

<body>

    <div class="mainBlock">

        <h1>Change Info</h1>
        <form action="../PHP/2021.03.12.06 CHANGE INFO.php" method="POST">
            <p>
                <label for="login">Login</label>
                <input type="text" name="login" value=<?php session_start();
                                                        echo $_SESSION['login'] ?> required>
            </p>

            <p>
                <label for="password">Password</label>
                <input type="text" name="password" value=<?php echo $_SESSION['password'] ?> required>
            </p>

            <p>
                <label for="password">Email</label>
                <input type="text" name="email" value=<?php echo $_SESSION['email'] ?> required>
            </p>

            <input type="submit">
        </form>

        <a href="../PHP/2021.03.12.03 MAIN PAGE AFTER LOGIN.php">
            <p>Вернуться обратно</p>
        </a>

    </div>

</body>

</html>