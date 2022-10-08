<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="../CSS/2021.03.12.01.css">
    <title>Main Page</title>
</head>

<body>

    <div class="mainBlock">
        <h1>Welcome, <?php session_start();
                        echo $_SESSION['login'] ?></h1>

        <?php

        if (isset($_COOKIE['counter'])) {
            $_COOKIE['counter']++;
            setcookie("counter", $_COOKIE['counter']);
            echo 'It is your ' . $_COOKIE['counter'] . ' visit of our site';
        } else {
            setcookie("counter", 1);
            echo 'It is your ' . 1 . ' visit of our site';
        }
        ?>
        <br>

        <?php

        if (isset($_COOKIE['day'])) {
            $day = $_COOKIE['day'];
            $month = $_COOKIE['month'];
            $year = $_COOKIE['year'];


            $cd = new \DateTime('today'); // Сегодня, время 00:00:00
            $bd = new \DateTime($year . "-" . $month . "-" . $day); // Объект Дата дня рождения
            $bd->setDate($cd->format('Y'), $bd->format('m'), $bd->format('d')); // Устанавливаем текущий год, оставляем месяц и день
            $tmp = $cd->diff($bd); // Разница дат
            if ($tmp->invert) { // Если в этом году уже был (разница "отрицательная")
                $bd->modify('+1 year'); // Добавляем год
                $tmp = $cd->diff($bd); // Снова вычисляем разницу
            }
            $message3 = $tmp->days; // Результат в днях
            if ($message3 == 0) {
                $message3 = 'Happy birthday!';
                echo $message3;
            } else {
                $message3 = 'Until your birthday: ' . $message3 . ' days';
                echo $message3;
            }
        }
        else
        {
            echo "You didn't add your date of Birthday";
        }

        ?>
        <br>

        <?php

        if (!isset($_SESSION['start'])) $_SESSION['start'] = time();
        $time_spent = time() - $_SESSION['start'];

        echo "You entered in account " . $time_spent . " seconds ago";

        ?>
        <br>



        <a href="../PHP/2021.03.12.04 CHANGE INFO FORM.php"><button>Change Info</button></a><br>

        <a href="../PHP/2021.03.12.07 SET BIRTHDAY.php"><button>Set Birthday</button></a><br>

        <a href="../PHP/2021.03.12.05 EXIT.php"><button>Exit</button></a>
    </div>

</body>

</html>