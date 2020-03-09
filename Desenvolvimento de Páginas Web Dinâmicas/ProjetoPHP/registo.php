<!DOCTYPE html>

<!--
    Copyright (c) Carlos Tojal 2020
    ProjetoPHP
    registo.php
-->

<html>
    <head>
        <title> Registo - ProjetoPHP </title>
    </head>
    <body>
        <?php require("header.php"); ?>
        <h2> Registo </h2>
        <form action="processar_registo.php" method="POST">
            <p> Username: </p>
            <input type="text" name="username"><br>
            <p> Password: </p>
            <input type="password" name="password"><br><br>
            <p> Email: </p>
            <input type="email" name="email"><br><br>
            <p> Nome: </p>
            <input type="text" name="name"><br><br>
            <p> Apelido: </p>
            <input type="text" name="apelido"><br><br>
            <p> Data de nascimento: </p>
            <input type="date" name="birth_date"><br><br>
            <input type="submit" value="Registo">
        </form>
    </body>
</html>
