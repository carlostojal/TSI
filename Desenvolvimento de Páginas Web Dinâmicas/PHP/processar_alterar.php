<?php
    include("conexao.php");

    $id = $_POST['id'];
    $username = $_POST['username'];
    $password = $_POST['password'];
    $email = $_POST['email'];
    $role = $_POST['role'];

    $sql = "UPDATE utilizadores SET nome_utilizador = '$username', palavra_passe = '$password', email = '$email', role = '$role' WHERE id_utilizador = '$id'";
    $res = mysqli_query($con, $sql);

    if($res)
        header("Location: alterar_utilizador.php?msg=Alteração+salva+com+sucesso");
    else
        header("Location: alterar_utilizador.php?msg=Erro+ao+conectar+à+base+de+dados");
?>