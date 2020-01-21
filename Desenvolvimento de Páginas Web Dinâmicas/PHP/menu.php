<?php
    session_start();
    if(!isset($_SESSION['username']))
        header("Location: login.php");
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title> Menu </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    </head>
    <body>
        <h1> Menu </h1>
        <p> <b>Olá, <?php echo $_SESSION['username']."</b> (".$_SESSION['role'].")" ?> </p>
        <ul>
            <li><a href="registar_utilizador.php"> Registar Utilizador </a></li>
            <li><a href="ver_utilizador.php"> Ver Utilizador </a></li>
            <?php 
                if($_SESSION['role'] == "admin")
                    echo "<li><a href='alterar_utilizador.php'> Alterar Utilizador </a></li>
                    <li><a href='eliminar_utilizador.php'> Eliminar Utilizador </a></li>";
            ?>
            <li><a href="logout.php"> Terminar Sessão </a></li>
        </ul>
    </body>
</html>