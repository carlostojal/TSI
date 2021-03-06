
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    alterar_utilizador.php
-->

<?php
    require("conexao.php");
    session_start();

    // Não permite que utilizadores não registados utilizem a página
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
        <title> Alterar Utilizador </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="bootstrap.min.css">
    </head>
    <body>
        <h1> Alterar Utilizador </h1>
        <?php include("menu1.php") ?>
        <form action="alterar_utilizador.php">
            <input type="text" name="q" placeholder="Pesquisa">
            <input type="submit" value="Pesquisar" class="btn btn-primary">
            <a href="alterar_utilizador.php" class="btn btn-outline-primary"> Remover filtro </a>
        </form>
        <?php 
            if(isset($_GET['msg'])) echo $_GET['msg'];
            // Lista os dados de todos os utilizadores em formulários
            if(mysqli_num_rows($res) > 0) {
                while($data = mysqli_fetch_array($res)) {
                    if($data[0] == $_SESSION['id'] || $_SESSION['role'] == "admin") {
        ?>
        <div class="container">
            <div class="panel panel-default">
                <div class="panel-body">
                    <form class="container" class="panel panel-default" action="processar_alterar.php" method="POST">
                        <div class="form-group">
                            <label for="id"> ID de Utilizador: </label>
                            <input type="number" class="form-control" name="id" value="<?php /* Preenche o campo com o valor da base de dados */ echo $data[0] ?>" readonly>
                        </div>
                        <div class="form-group">
                            <label for="username"> Nome de Utilizador: </label>
                            <input type="text" class="form-control" name="username" placeholder="Introduzir nome de utilizador" value="<?php echo $data[1] ?>">
                        </div>
                        <div class="form-group">
                            <label for="password"> Palavra passe: </label>
                            <input type="text" class="form-control" name="password" placeholder="Introduzir palavra passe" value="<?php echo $data[2] ?>">
                        </div>
                        <div class="form-group">
                            <label for="password"> Email: </label>
                            <input type="email" class="form-control" name="email" placeholder="Introduzir email" value="<?php echo $data[3] ?>">
                        </div>
                        <div class="form-group">
                            <input type="radio" name="role" value="admin" <?php /* Seleciona a opção correspondente (admin/user) */ if($data[4] == "admin") echo "checked" ?>> Administrador <br>
                            <input type="radio" name="role" value="user" <?php if($data[4] == "user") echo "checked" ?>> Utilizador <br>
                        </div>
                        <div class="panel-footer">
                            <button type="submit" value="Iniciar sessão" class="btn btn-primary"> Salvar Alterações </button>
                        </div>
                        <br><br>
                    </form>
                </div>
            </div>
        </div>
        <?php 
                    }
                }
            } else {
                echo "Não existem resultados.";
            }
        ?>
    </body>
</html>