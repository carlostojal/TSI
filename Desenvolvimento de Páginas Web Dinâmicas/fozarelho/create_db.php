<?php
    $sql = "CREATE DATABASE carlostojal;";
    $sql .= "CREATE TABLE carlostojal.utilizador (
    username VARCHAR(20) NOT NULL,
    password VARCHAR(60) NOT NULL,
    email VARCHAR(30) NOT NULL,
    nome VARCHAR(15) NOT NULL,
    apelido VARCHAR(15) NOT NULL,
    data_de_nascimento DATE NOT NULL,
    PRIMARY KEY (username));";

    require("connection.php");
    mysqli_query($con, $sql);
?>