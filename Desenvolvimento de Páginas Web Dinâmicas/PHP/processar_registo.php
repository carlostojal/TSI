<?php
    include("conexao.php");

    $username = $_POST['username'];
    $password = $_POST['password'];
    $email = $_POST['email'];

    $sql = "INSERT INTO utilizadores (nome_utilizador, palavra_passe, email) VALUES ('$username','$password','$email')";
    $res = mysqli_query($con, $sql);
    if($res)
        header("Location: login.php?msg=Registado+com+sucesso")
?>