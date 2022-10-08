-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Время создания: Июн 22 2021 г., 14:10
-- Версия сервера: 10.4.18-MariaDB
-- Версия PHP: 8.0.3

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `airport`
--

-- --------------------------------------------------------

--
-- Структура таблицы `flyway_schema_history`
--

CREATE TABLE `flyway_schema_history` (
  `installed_rank` int(11) NOT NULL,
  `version` varchar(50) DEFAULT NULL,
  `description` varchar(200) NOT NULL,
  `type` varchar(20) NOT NULL,
  `script` varchar(1000) NOT NULL,
  `checksum` int(11) DEFAULT NULL,
  `installed_by` varchar(100) NOT NULL,
  `installed_on` timestamp NOT NULL DEFAULT current_timestamp(),
  `execution_time` int(11) NOT NULL,
  `success` tinyint(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `flyway_schema_history`
--

INSERT INTO `flyway_schema_history` (`installed_rank`, `version`, `description`, `type`, `script`, `checksum`, `installed_by`, `installed_on`, `execution_time`, `success`) VALUES
(1, '1', 'passenger schema', 'SQL', 'V1__passenger_schema.sql', -179319863, 'root', '2021-06-14 11:06:00', 25, 1),
(2, '2', 'route schema', 'SQL', 'V2__route_schema.sql', 555063443, 'root', '2021-06-14 11:06:31', 23, 1),
(3, '3', 'table constraints', 'SQL', 'V3__table_constraints.sql', 1131692964, 'root', '2021-06-14 11:10:22', 65, 1),
(4, '4', 'dates for passenger table', 'SQL', 'V4__dates_for_passenger_table.sql', -1634312474, 'root', '2021-06-14 11:10:22', 3, 1),
(5, '5', 'dates for route table', 'SQL', 'V5__dates_for_route_table.sql', -1726490214, 'root', '2021-06-14 11:10:22', 3, 1);

-- --------------------------------------------------------

--
-- Структура таблицы `passenger`
--

CREATE TABLE `passenger` (
  `passenger_code` bigint(20) NOT NULL,
  `name` varchar(255) DEFAULT NULL,
  `phone` varchar(255) DEFAULT NULL,
  `surname` varchar(255) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `passenger`
--

INSERT INTO `passenger` (`passenger_code`, `name`, `phone`, `surname`) VALUES
(1, 'Alexand', '069547222', 'Vicev'),
(2, 'Artur', '065488995', 'Iancioglo'),
(3, 'Maksim', '069874115', 'Rusnak'),
(4, 'Alexandr', '078146987', 'Sirbu'),
(7, 'Oleg', '069875444', 'Petrov');

-- --------------------------------------------------------

--
-- Структура таблицы `route`
--

CREATE TABLE `route` (
  `code_route` bigint(20) NOT NULL,
  `class` varchar(255) DEFAULT NULL,
  `destination` varchar(255) DEFAULT NULL,
  `price` int(11) DEFAULT NULL CHECK (`price` >= 1 and `price` <= 9999999),
  `passenger_code` bigint(20) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `route`
--

INSERT INTO `route` (`code_route`, `class`, `destination`, `price`, `passenger_code`) VALUES
(1, 'business', 'Moscow', 50, 1),
(2, 'econom', 'Chisinau', 100, 2),
(3, 'business', 'Rome', 900, 3),
(4, 'business', 'Tokyo', 500, 4),
(5, 'business', 'Moscow', 50, 1),
(6, 'business', 'Tokyo', 1000, 7),
(7, 'business', 'Tokyo', 500, 1),
(8, 'business', 'Tokyo', 1000, 1);

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `flyway_schema_history`
--
ALTER TABLE `flyway_schema_history`
  ADD PRIMARY KEY (`installed_rank`),
  ADD KEY `flyway_schema_history_s_idx` (`success`);

--
-- Индексы таблицы `passenger`
--
ALTER TABLE `passenger`
  ADD PRIMARY KEY (`passenger_code`);

--
-- Индексы таблицы `route`
--
ALTER TABLE `route`
  ADD PRIMARY KEY (`code_route`),
  ADD KEY `FK_ROUTE_PASSENGER_CODE` (`passenger_code`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `passenger`
--
ALTER TABLE `passenger`
  MODIFY `passenger_code` bigint(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=12;

--
-- AUTO_INCREMENT для таблицы `route`
--
ALTER TABLE `route`
  MODIFY `code_route` bigint(20) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=9;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `route`
--
ALTER TABLE `route`
  ADD CONSTRAINT `FK_ROUTE_PASSENGER_CODE` FOREIGN KEY (`passenger_code`) REFERENCES `passenger` (`passenger_code`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
