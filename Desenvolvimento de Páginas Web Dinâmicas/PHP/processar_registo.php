
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    processar_registo.php
-->

<?php
    include("conexao.php");

    $username = $_POST['username'];
    $password = $_POST['password'];
    $email = $_POST['email'];

    // Insere na base de dados um utilizador com os dados passados pelo formulário
    $sql = "INSERT INTO utilizadores (nome_utilizador, palavra_passe, email, role) VALUES ('$username','$password','$email', 'user')";
    $res = mysqli_query($con, $sql);
    if($res)
        header("Location: menu.php")
?>