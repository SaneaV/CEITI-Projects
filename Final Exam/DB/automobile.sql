-- phpMyAdmin SQL Dump
-- version 5.1.0
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Время создания: Июн 22 2021 г., 14:31
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
-- База данных: `automobile`
--

-- --------------------------------------------------------

--
-- Структура таблицы `automobil`
--

CREATE TABLE `automobil` (
  `cod_automobil` int(11) NOT NULL,
  `marka` varchar(50) NOT NULL,
  `model` varchar(50) NOT NULL,
  `nr_usi` int(11) NOT NULL,
  `pret` int(11) NOT NULL,
  `cod_producator` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `automobil`
--

INSERT INTO `automobil` (`cod_automobil`, `marka`, `model`, `nr_usi`, `pret`, `cod_producator`) VALUES
(1, 'BMW', 'M440i Convertible', 2, 5000, 1),
(2, 'Honda', 'Civic', 4, 1500, 2),
(3, 'Kia', 'Sorento Hybrid', 4, 6000, 3);

-- --------------------------------------------------------

--
-- Структура таблицы `producator`
--

CREATE TABLE `producator` (
  `cod_producator` int(11) NOT NULL,
  `an_lansare` int(11) NOT NULL,
  `denumire` varchar(50) NOT NULL,
  `telefon` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `producator`
--

INSERT INTO `producator` (`cod_producator`, `an_lansare`, `denumire`, `telefon`) VALUES
(1, 1916, 'BMW', '069654112'),
(2, 1946, 'Honda', '069874552'),
(3, 1944, 'Kia', '069874556');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `automobil`
--
ALTER TABLE `automobil`
  ADD PRIMARY KEY (`cod_automobil`),
  ADD KEY `FK_COD_PRODUCATOR` (`cod_producator`);

--
-- Индексы таблицы `producator`
--
ALTER TABLE `producator`
  ADD PRIMARY KEY (`cod_producator`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `automobil`
--
ALTER TABLE `automobil`
  MODIFY `cod_automobil` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- AUTO_INCREMENT для таблицы `producator`
--
ALTER TABLE `producator`
  MODIFY `cod_producator` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `automobil`
--
ALTER TABLE `automobil`
  ADD CONSTRAINT `FK_COD_AUTOMOBIL` FOREIGN KEY (`cod_producator`) REFERENCES `producator` (`cod_producator`),
  ADD CONSTRAINT `FK_COD_PRODUCATOR` FOREIGN KEY (`cod_producator`) REFERENCES `producator` (`cod_producator`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
