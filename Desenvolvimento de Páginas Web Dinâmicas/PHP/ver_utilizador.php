
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    ver_utilizador.php
-->

<?php
    require("conexao.php");
    session_start();
    if(!isset($_SESSION['username']))
        header("Location: login.php");

    $sql = "SELECT * FROM utilizadores";
    if(isset($_GET['q'])) {
        $search = $_GET['q'];
        $sql = "SELECT * FROM utilizadores WHERE id_utilizador = '$search' OR nome_utilizador LIKE '%$search%' OR email LIKE '%$search%' OR role = '$search'";
    }
    $res = mysqli_query($con, $sql);
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title> Ver Utilizador </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    </head>
    <body>
        <h1> Ver Utilizador </h1>
        <?php include("menu1.php") ?>
        <form action="ver_utilizador.php">
            <input type="text" name="q" placeholder="Pesquisa">
            <input type="submit" value="Pesquisar" class="btn btn-primary">
            <a href="ver_utilizador.php" class="btn btn-outline-primary"> Remover filtro </a>
        </form>
        <table class="table">
            <tr>
                <th> ID de Utilizador </th>
                <th> Nome de Utilizador </th>
                <th> Palavra Passe </th>
                <th> Email </th>
                <th> Privilégios </th>
            </tr>
            <?php 
                if(mysqli_num_rows($res) > 0) {
                    while($data = mysqli_fetch_array($res)) {
            ?>
            <tr>
                <td> <?php echo $data[0] ?> </td>
                <td> <?php echo $data[1] ?> </td>
                <td> <?php echo $data[2] ?> </td>
                <td> <?php echo $data[3] ?> </td>
                <td> <?php echo $data[4] ?> </td>
            </tr>
            <?php 
                    }
                } else {
                    echo "Não existem resultados.";
                }
            ?>
        </table>
    </body>
</html>