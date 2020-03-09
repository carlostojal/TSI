<!DOCTYPE html>

<!--
    Copyright (c) Carlos Tojal 2020
    ProjetoPHP
    login.php
-->

<html>
    <head>
        <title> Login - ProjetoPHP </title>
    </head>
    <body>
        <?php require("header.php"); ?>
        <h2> Login </h2>
        <form action="processar_login.php" method="POST">
            <p> Username ou email: </p>
            <input type="text" name="username_email"><br>
            <p> Password: </p>
            <input type="password" name="password"><br><br>
            <input type="submit" value="Login">
        </form>
    </body>
</html>
