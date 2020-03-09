<?php

    //
    // Copyright (c) Carlos Tojal 2020
    // ProjetoPHP
    // criar_db.php
    //

    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "carlostojal";

    $conn = mysqli_connect($servername, $username, $password);
    if(!$conn) {
        die("A conexão falhou: ".mysqli_connect_error());
    }

    $sql = "CREATE DATABASE $dbname";
    
    $res = mysqli_query($conn, $sql);

    if($res) {
        $conn = mysqli_connect($servername, $username, $password, $dbname);
        if(!$conn) {
            die("A conexão falhou: ".mysqli_connect_error());
        }
        $sql = "CREATE TABLE utilizador (
            username VARCHAR(20) PRIMARY KEY,
            password VARCHAR(40) NOT NULL,
            email VARCHAR(30),
            nome VARCHAR(20) NOT NULL,
            apelido VARCHAR(20) NOT NULL,
            data_de_nascimento DATE NOT NULL)"; 

        $res = mysqli_query($conn, $sql);

        if($res) {
            echo "Base de dados criada com sucesso.";
        } else {
            echo "Erro ao conectar à base de dados (2).";
        }
    } else { 
        echo "Erro ao conectar à base de dados (1).";
    }
?>
