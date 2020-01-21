
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    processar_login.php
-->

<?php
    include("conexao.php");
    session_start();

    $username = $_POST['username'];
    $password = $_POST['password'];

    // Verifica se existe na base de dados uma linha com o mesmo nome de utilizador e palavra-passe que os passados pelo formulário
    $sql = "SELECT * FROM utilizadores WHERE nome_utilizador = '$username' AND palavra_passe = '$password'";
    $res = mysqli_query($con, $sql);
    $data = mysqli_fetch_array($res);
    if(mysqli_num_rows($res) == 1) {
        $_SESSION['username'] = $username;
        $_SESSION['role'] = $data[4];
        header("Location: menu.php");
    }
    else {
        header("Location: login.php?msg=Nome+de+utilizador+ou+palavra+passe+incorretos+");
    }
?>