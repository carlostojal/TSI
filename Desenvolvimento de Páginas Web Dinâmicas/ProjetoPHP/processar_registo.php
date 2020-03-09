<?php

    //
    // Copyright (c) Carlos Tojal 2020
    // ProjetoPHP
    // processar_registo.php
    //

    require("connection.php");

    $username = $_POST['username_email'];
    $password = $_POST['password']; $email = $_POST['email'];
    $nome = $_POST['name'];

    $sql = "INSERT INTO utilizador (username, password, email, nome, apelido, data_de_nascimento) VALUES ('$username', '$password', 

    $res = mysqli_query($conn, $sql);

    if(mysqli_num_rows($res) == 1)
        echo "Sucesso";
    else
        header("Location: login.php");
?>
