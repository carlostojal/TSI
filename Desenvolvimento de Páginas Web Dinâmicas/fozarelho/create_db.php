<?php

    $host = "localhost";
    $username = "root";
    $password = "";

    $con = mysqli_connect($host, $username, $password);

    $sql = "CREATE DATABASE carlostojal";

    mysqli_query($con, $sql);

    mysqli_select_db($con, "carlostojal");
    
    $sql = "CREATE TABLE utilizador (
    username VARCHAR(20) NOT NULL,
    password VARCHAR(60) NOT NULL,
    email VARCHAR(30) NOT NULL,
    nome VARCHAR(15) NOT NULL,
    apelido VARCHAR(15) NOT NULL,
    data_de_nascimento DATE NOT NULL,
    PRIMARY KEY (username));";

    mysqli_query($con, $sql);

    $sql = "CREATE TABLE comentario (
    id INT NOT NULL AUTO_INCREMENT,
    username VARCHAR(20) NOT NULL,
    texto TEXT NOT NULL,
    data DATETIME NOT NULL,
    PRIMARY KEY (id));";

    mysqli_query($con, $sql);

    echo mysqli_error($con);
?>