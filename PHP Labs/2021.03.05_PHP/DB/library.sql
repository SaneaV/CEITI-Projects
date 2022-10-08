-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1
-- Время создания: Мар 05 2021 г., 13:36
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
-- База данных: `library`
--

-- --------------------------------------------------------

--
-- Структура таблицы `elib`
--

CREATE TABLE `elib` (
  `id` int(11) NOT NULL,
  `title` varchar(100) NOT NULL,
  `author` varchar(100) NOT NULL,
  `year` int(11) NOT NULL,
  `publishing` varchar(100) NOT NULL,
  `subjects` text NOT NULL,
  `price` int(11) NOT NULL,
  `photo` varchar(50) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Дамп данных таблицы `elib`
--

INSERT INTO `elib` (`id`, `title`, `author`, `year`, `publishing`, `subjects`, `price`, `photo`) VALUES
(1, 'The Four Winds: A Novel', 'Kristin Hannah', 2021, 'St. Martin\'s Press', 'From the #1 New York Times bestselling author of The Nightingale and The Great Alone comes an epic novel of love and heroism and hope, set against the backdrop of one of America’s most defining eras—the Great Depression.\r\n\r\nTexas, 1934. Millions are out of work and a drought has broken the Great Plains. Farmers are fighting to keep their land and their livelihoods as the crops are failing, the water is drying up, and dust threatens to bury them all. One of the darkest periods of the Great Depression, the Dust Bowl era, has arrived with a vengeance.\r\n\r\nIn this uncertain and dangerous time, Elsa Martinelli—like so many of her neighbors—must make an agonizing choice: fight for the land she loves or go west, to California, in search of a better life. The Four Winds is an indelible portrait of America and the American Dream, as seen through the eyes of one indomitable woman whose courage and sacrifice will come to define a generation.', 14, 'The_Four_Wind.jpeg'),
(2, 'The Paris Library: A Novel', 'Janet Skeslien Charles', 2021, 'Atria Books', 'Based on the true World War II story of the heroic librarians at the American Library in Paris, this is an unforgettable story of romance, friendship, family, and the power of literature to bring us together, perfect for fans of The Lilac Girls and The Paris Wife.\r\n\r\nParis, 1939: Young and ambitious Odile Souchet has it all: her handsome police officer beau and a dream job at the American Library in Paris. When the Nazis march into Paris, Odile stands to lose everything she holds dear, including her beloved library. Together with her fellow librarians, Odile joins the Resistance with the best weapons she has: books. But when the war finally ends, instead of freedom, Odile tastes the bitter sting of unspeakable betrayal.\r\n\r\nMontana, 1983: Lily is a lonely teenager looking for adventure in small-town Montana. Her interest is piqued by her solitary, elderly neighbor. As Lily uncovers more about her neighbor’s mysterious past, she finds that they share a love of language, the same longings, and the same intense jealousy, never suspecting that a dark secret from the past connects them.\r\n\r\nA powerful novel that explores the consequences of our choices and the relationships that make us who we are—family, friends, and favorite authors—The Paris Library shows that extraordinary heroism can sometimes be found in the quietest of places.', 15, 'The_Paris_Library.jpeg'),
(3, 'The Paris Dressmaker', 'Kristy Cambron', 2021, 'Thomas Nelson\r\n', 'Based on true accounts of how Parisiennes resisted the Nazi occupation in World War II—from fashion houses to the city streets—comes a story of two courageous women who risked everything to fight an evil they couldn’t abide.\r\n\r\nParis, 1939. Maison Chanel has closed, thrusting haute couture dressmaker Lila de Laurent out of the world of high fashion as Nazi soldiers invade the streets and the City of Lights slips into darkness. Lila’s life is now a series of rations, brutal restrictions, and carefully controlled propaganda while Paris is cut off from the rest of the world. Yet in hidden corners of the city, the faithful pledge to resist. Lila is drawn to La Resistance and is soon using her skills as a dressmaker to infiltrate the Nazi elite. She takes their measurements and designs masterpieces, all while collecting secrets in the glamorous Hôtel Ritz—the heart of the Nazis’ Parisian headquarters. But when dashing René Touliard suddenly reenters her world, Lila finds her heart tangled between determination to help save his Jewish family and bolstering the fight for liberation.\r\n\r\nParis, 1943. Sandrine Paquet’s job is to catalog the priceless works of art bound for the Führer’s Berlin, masterpieces stolen from prominent Jewish families. But behind closed doors, she secretly forages for information from the underground resistance. Beneath her compliant façade lies a woman bent on uncovering the fate of her missing husband . . . but at what cost? As Hitler’s regime crumbles, Sandrine is drawn in deeper when she uncrates an exquisite blush Chanel gown concealing a cryptic message that may reveal the fate of a dressmaker who vanished from within the fashion elite.\r\n\r\nTold across the span of the Nazi occupation, The Paris Dressmaker highlights the brave women who used everything in their power to resist darkness and restore light to their world.\r\n\r\nPraise for The Paris Dressmaker:\r\n\r\n“Unimaginable heartache, unforgettable romance, and cheering defiance against the oppression the Nazis inflicted on Paris; readers will be swept away into a story where battle-scarred good at last rings victory over evil.” —J’nell Ciesielski, author of The Socialite\r\n\r\n“Stunning. With as much skill and care as the title’s namesake possesses, The Paris Dressmaker weaves together the stories of two heroines who boldly defy the darkness that descends on the City of Light.” —Jocelyn Green, Christy Award-winning author of Shadows of the White City\r\n\r\n“A thoroughly satisfying blend of memorable characters, evocative writing, and wartime drama that seamlessly transport you to the City of Light at its most desperate hour.” —Susan Meissner, bestselling author of The Nature of Fragile Things\r\n\r\n“Kristy Cambron deftly weaves multiple timelines to craft a story as complex and romantic and beautiful as a couture gown. In addition, Lila and Sandrine’s strength and courage in a troubled world inspire us to live likewise. Tres magnifique!” —Sarah Sundin, bestselling and award-winning author of When Twilight Breaks and the Sunrise at Normandy series\r\n\r\n“With real life historical details woven in with her fictional tale, the story popped off the page. Readers will be thinking of this book long after they\'ve read the last word.” —Rachel Hauck, New York Times bestselling author\r\n\r\n“A well-researched and beautifully interwoven treatise on courage and conviction in the midst of oppression.” —Rachel McMillan, author of The London Restoration and The Mozart Code\r\n\r\nStand-alone WWII novel\r\nFull-length, approximately 115,000 words\r\nIncludes discussion questions for book clubs', 10, 'The_Paris_Dressmaker.jpeg'),
(4, 'When Twilight Breaks', 'Sarah Sundin ', 2021, 'Revell', '\"Two Americans meet in 1938 in the heart of Nazi Germany. Their efforts to expose oppression attract unwanted attention, pulling them deeper into danger as the world marches toward war\"--', 10, 'When_Twilight_Breaks.jpeg'),
(5, 'Moonlight School', 'Douglas Fisher', 2021, 'Revell', 'Haunted by her sister\'s mysterious disappearance, Lucy Wilson arrives in Rowan County, Kentucky, in the spring of 1911 to work for Cora Wilson Stewart, superintendent of education. When Cora sends Lucy into the hills to act as scribe for the mountain people, she is repelled by the primitive conditions and intellectual poverty she encounters. Few adults can read and write.\r\n\r\nBorn in those hills, Cora knows the plague of illiteracy. So does Brother Wyatt, a singing schoolmaster who travels through the hills. Involving Lucy and Wyatt, Cora hatches a plan to open the schoolhouses to adults on moonlit nights. The best way to combat poverty, she believes, is to eliminate illiteracy. But will the people come?\r\n\r\nAs Lucy emerges from a life in the shadows, she finds purpose; or maybe purpose finds her. With purpose comes answers to her questions, and something else she hadn\'t expected: love.\r\n\r\nInspired by the true events of the Moonlight Schools, this standalone novel from bestselling author Suzanne Woods Fisher brings to life the story that shocked the nation into taking adult literacy seriously. You\'ll finish the last page of this enthralling story with deep gratitude for the gift of reading.', 12, 'Moonlight_School.jpeg'),
(6, 'The Pleasing Hour: A Novel', 'Lily King', 2010, 'Grove Press', 'The award-winning novel of a young American girl in France—hailed as “an impressive debut” that is “written with quiet, lyric forcefulness” (Elle).\r\n \r\nA New York Times Notable Book\r\n \r\nYoung, inexperienced, and fleeing a terrible personal loss, Rosie—the new au pair to the Tivot family estate in France—finds herself ill at ease when trying to connect with Nicole, the cool, distant, and beautifully polished mother of the three children she cares for. There is something about the woman that both fascinates and unnerves Rosie.\r\n \r\nThe same is true of the rest of the Tivot clan. Nicole’s dissatisfied husband, Marc, and their children all seem to be caught in an unending struggle against each other for love and acceptance. Only when Rosie is sent to care for Nicole’s now-elderly guardian—the storyteller of the family’s secrets—does she finally discover the truth. There, Rosie will learn of a past darkened by war, duplicity, and a tragedy that still resonates in the Tivot’s lives . . .\r\n \r\nWith this novel of family, betrayal, and the naïveté of youth, Lily King has spun a story that is “powerful . . . splendid . . . [and all] so assured that it’s hard to believe the book itself is her debut” (The New York Times Book Review).\r\n \r\n“Expertly constructed, full of surprises, superbly paced and sweetly sad, King’s book hardly reads like a first novel.” —Publishers Weekly', 10, 'The_Pleasing_Hour_A_Novel.jpg'),
(7, 'Firefly Lane: A Novel', 'Kristin Hannah', 2008, 'St. Martin\'s Press', 'From the New York Times bestselling author of On Mystic Lake comes a powerful novel of love, loss, and the magic of friendship. . . .\r\n\r\nIn the turbulent summer of 1974, Kate Mularkey has accepted her place at the bottom of the eighth-grade social food chain. Then, to her amazement, the \"coolest girl in the world\" moves in across the street and wants to be her friend. Tully Hart seems to have it all---beauty, brains, ambition. On the surface they are as opposite as two people can be: Kate, doomed to be forever uncool, with a loving family who mortifies her at every turn. Tully, steeped in glamour and mystery, but with a secret that is destroying her. They make a pact to be best friends forever; by summer\'s end they\'ve become TullyandKate. Inseparable.', 8, 'Firefly_Lane_A_Novel.jpg');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `elib`
--
ALTER TABLE `elib`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `elib`
--
ALTER TABLE `elib`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
