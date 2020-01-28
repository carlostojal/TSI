
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    menu.php
-->

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
        <link rel="stylesheet" href="bootstrap.min.css">
    </head>
    <body>
        <h1> Menu </h1>
        <p> Olá, <b><?php echo $_SESSION['username']."</b> (".$_SESSION['role'].")" ?> </p>
        <?php include("menu1.php") ?>
    </body>
</html>