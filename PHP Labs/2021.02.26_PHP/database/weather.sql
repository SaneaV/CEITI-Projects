-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Время создания: Фев 26 2021 г., 10:52
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
-- База данных: `weather`
--

-- --------------------------------------------------------

--
-- Структура таблицы `weather_forecast`
--

CREATE TABLE `weather_forecast` (
  `Date_W` date NOT NULL,
  `Temperature` int(11) NOT NULL,
  `Wind` int(11) NOT NULL,
  `Shortly` varchar(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `weather_forecast`
--

INSERT INTO `weather_forecast` (`Date_W`, `Temperature`, `Wind`, `Shortly`) VALUES
('2021-02-26', 5, 6, 'sun'),
('2021-02-27', 7, 8, 'cls'),
('2021-02-28', 2, 10, 'ran'),
('2021-03-01', 0, 8, 'wnd'),
('2021-03-02', -5, 10, 'snw'),
('2021-03-03', -5, 11, 'snw'),
('2021-03-04', -5, 11, 'snw'),
('2021-03-05', 5, 2, 'sun'),
('2021-03-06', 5, 5, 'sun');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `weather_forecast`
--
ALTER TABLE `weather_forecast`
  ADD PRIMARY KEY (`Date_W`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
