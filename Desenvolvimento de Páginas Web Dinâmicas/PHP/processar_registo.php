<?php
    include("conexao.php");

    $username = $_POST['username'];
    $password = $_POST['password'];
    $email = $_POST['email'];

    $sql = "INSERT INTO utilizadores (nome_utilizador, palavra_passe, email, role) VALUES ('$username','$password','$email', 'user')";
    $res = mysqli_query($con, $sql);
    if($res)
        header("Location: menu.php")
?>