<?php

    //
    // Copyright (c) Carlos Tojal 2020
    // ProjetoPHP
    // processar_login.php
    //

    require("connection.php");

    $username_email = $_POST['username_email'];
    $password = $_POST['password'];

    $sql = "SELECT * FROM utilizador WHERE (username = '$username_email' OR email = '$username_email') AND password = '".SHA1($password)."'";

    $res = mysqli_query($conn, $sql);

    if(mysqli_num_rows($res) == 1)
        echo "Sucesso";
    else
        header("Location: login.php");
?>
