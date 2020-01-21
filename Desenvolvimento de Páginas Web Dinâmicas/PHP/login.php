
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    login.php
-->

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title> Autenticação de Utilizadores </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    </head>
    <body>
        <h1> Autenticação de Utilizadores </h1>
        <form action="processar_login.php" method="POST">
            <div class="form-group">
                <label for="username"> Nome de Utilizador: </label>
                <input type="text" class="form-control" name="username" placeholder="Introduzir nome de utilizador">
            </div>
            <div class="form-group">
                <label for="password"> Palavra passe: </label>
                <input type="password" class="form-control" name="password" placeholder="Introduzir palavra passe">
            </div>
            <br><?php if(isset($_GET['msg'])) echo $_GET['msg'] ?><br>
            <button type="submit" value="Iniciar sessão" class="btn btn-primary"> Iniciar sessão </button>
            <a href="registar_utilizador.php" class="btn btn-outline-primary"> Registar </a>
        </form>
    </body>
</html>