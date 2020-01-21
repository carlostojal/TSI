
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
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    </head>
    <body>
        <h1> Registo de Utilizadores </h1>
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
    </body>
</html>