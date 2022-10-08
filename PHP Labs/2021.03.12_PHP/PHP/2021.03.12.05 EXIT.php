<?php
session_start();
session_destroy();
echo "<a href=\"../HTML/2021.03.12.01 HOME PAGE.html\"> <p>Вернуться на главную страницу</p></a>";
setcookie('counter');
setcookie('day');
setcookie('month');
setcookie('year');
setcookie('start');

