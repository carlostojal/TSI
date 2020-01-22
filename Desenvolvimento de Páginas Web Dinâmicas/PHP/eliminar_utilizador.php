
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    eliminar_utilizador.php
-->

<?php
    require("conexao.php");
    session_start();

    // Não permite que utilizadorem sem sessão iniciada utilizem a página
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
        <title> Eliminar Utilizador </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    </head>
    <body>
        <h1> Eliminar Utilizador </h1>
        <form action="eliminar_utilizador.php">
            <input type="text" name="q" placeholder="Pesquisa">
            <input type="submit" value="Pesquisar" class="btn btn-primary">
            <a href="ver_utilizador.php" class="btn btn-outline-primary"> Remover filtro </a>
        </form>
        <?php if(isset($_GET['msg'])) echo $_GET['msg'] ?>
        <table border="2">
            <tr>
                <th> ID de Utilizador </th>
                <th> Nome de Utilizador </th>
                <th> Palavra Passe </th>
                <th> Email </th>
                <th> Privilégios </th>
                <th> Ação </th>
            </tr>
            <?php 
                // Lista os dados dos utilizadores numa tabela e gera um botão para eliminar com o id passado por GET
                if(mysqli_num_rows($res) > 0) {
                    while($data = mysqli_fetch_array($res)) {
                        if($data[0] == $_SESSION['id'] || $_SESSION['role'] == "admin") {
            ?>
            <tr>
                <td> <?php echo $data[0] ?> </td>
                <td> <?php echo $data[1] ?> </td>
                <td> <?php echo $data[2] ?> </td>
                <td> <?php echo $data[3] ?> </td>
                <td> <?php echo $data[4] ?> </td>
                <td><a href="processar_eliminar.php?id=<?php echo $data[0] ?>" class="btn btn-danger"> Eliminar </a></td>
            </tr>
            <?php 
                        }
                    }
                } else {
                    echo "Não existem resultados.";
                }
            ?>
        </table>
        <a href="menu.php" class="btn btn-primary"> Voltar </a>
    </body>
</html>