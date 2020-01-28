
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    registar_utilizador.php
-->

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title> Registo de Utilizadores </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="bootstrap.min.css">
    </head>
    <body>
        <h1> Registo de Utilizadores </h1>
        <?php include("menu1.php") ?>
        <div class="container">
            <form action="processar_registo.php" method="POST">
                <div class="form-group">
                    <label for="username"> Nome de Utilizador: </label>
                    <input type="text" class="form-control" name="username" placeholder="Introduzir nome de utilizador">
                </div>
                <div class="form-group">
                    <label for="password"> Palavra passe: </label>
                    <input type="password" class="form-control" name="password" placeholder="Introduzir palavra passe">
                </div>
                <div class="form-group">
                    <label for="password"> Email: </label>
                    <input type="email" class="form-control" name="email" placeholder="Introduzir email">
                </div>
                <br><?php if(isset($_GET['erro'])) echo $_GET['erro'] ?><br>
                <button type="submit" value="Iniciar sessão" class="btn btn-primary"> Registar </button>
                <a href="login.php" class="btn btn-outline-primary"> Iniciar sessão </a>
            </form>
        </div>
    </body>
</html>