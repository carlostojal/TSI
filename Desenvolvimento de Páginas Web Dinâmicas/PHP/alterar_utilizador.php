
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

    // Não permite que utilizadores normais utilizem a página
    if($_SESSION['role'] == "admin") {
        $sql = "SELECT * FROM utilizadores";
        $res = mysqli_query($con, $sql);
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title> Alterar Utilizador </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    </head>
    <body>
        <h1> Alterar Utilizador </h1>
        <?php 
            if(isset($_GET['msg'])) echo $_GET['msg'];
            // Lista os dados de todos os utilizadores em formulários
            while($data = mysqli_fetch_array($res)) {
        ?>
        <form action="processar_alterar.php" method="POST">
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
            <button type="submit" value="Iniciar sessão" class="btn btn-primary"> Salvar Alterações </button>
            <br><br>
        </form>
        <?php 
            }
        ?>
    </body>
</html>

<?php 
    } else {
        header("location: menu.php");
    }
?>