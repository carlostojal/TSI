-- phpMyAdmin SQL Dump
-- version 4.9.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Nov 11, 2019 at 09:55 PM
-- Server version: 10.3.16-MariaDB
-- PHP Version: 7.3.10

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET AUTOCOMMIT = 0;
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `id11076921_fozarelho`
--

-- --------------------------------------------------------

--
-- Table structure for table `visitantes`
--

CREATE TABLE `visitantes` (
  `id` int(11) NOT NULL,
  `name` varchar(50) COLLATE latin1_general_cs NOT NULL,
  `age` int(11) NOT NULL,
  `country` text COLLATE latin1_general_cs NOT NULL,
  `classification` int(11) NOT NULL,
  `opinion` text COLLATE latin1_general_cs NOT NULL,
  `divulgation` tinyint(1) NOT NULL,
  `year` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1 COLLATE=latin1_general_cs;

--
-- Dumping data for table `visitantes`
--

INSERT INTO `visitantes` (`id`, `name`, `age`, `country`, `classification`, `opinion`, `divulgation`, `year`) VALUES
(1, 'Carlos Tojal', 15, 'Portugal', 5, 'Praia agradável, natureza envolvente e ambiente relaxado.', 1, 2019),
(7, 'Alexandre Miguel', 16, 'Portugal', 3, 'Senti que o programador nao conseguiu extrair o melhor dos seus recursos', 1, 2019);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `visitantes`
--
ALTER TABLE `visitantes`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `visitantes`
--
ALTER TABLE `visitantes`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
