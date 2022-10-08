-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Время создания: Мар 23 2021 г., 18:29
-- Версия сервера: 10.4.17-MariaDB
-- Версия PHP: 8.0.2

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `cars`
--

-- --------------------------------------------------------

--
-- Структура таблицы `autopark`
--

CREATE TABLE `autopark` (
  `id` int(11) NOT NULL,
  `mark` varchar(100) NOT NULL,
  `model` varchar(200) NOT NULL,
  `year` int(11) NOT NULL,
  `engine_capacity` float NOT NULL,
  `fuel` varchar(50) NOT NULL,
  `transmission` varchar(50) NOT NULL,
  `price` int(11) NOT NULL,
  `photo` varchar(100) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `autopark`
--

INSERT INTO `autopark` (`id`, `mark`, `model`, `year`, `engine_capacity`, `fuel`, `transmission`, `price`, `photo`) VALUES
(3, 'Mercedes', '190 evo 2', 1995, 2.3, 'gasoline', 'automate', 5000, 'mercedes_190_evo_2.jpg\r\n'),
(4, 'Citroen', 'c5', 2000, 2.2, 'gasoline', 'manual', 2300, 'citroen_c5.jpg\r\n'),
(6, 'Wolksvagen', 'Polo 5', 2011, 1.9, 'gasoline', 'manual', 2000, 'wolksvagen_polo_5.jpg\r\n'),
(11, 'Mini Cooper', 's', 2004, 1.4, 'gasoline', 'manual', 1400, 'mini_cooper_s.jpg');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `autopark`
--
ALTER TABLE `autopark`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `autopark`
--
ALTER TABLE `autopark`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=13;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
