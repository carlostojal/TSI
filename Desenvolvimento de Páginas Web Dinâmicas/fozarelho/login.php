<?php
    if(isset($_GET['error'])) {
        if($_GET['error'] == "empty")
            echo "<script>alert('Tem campos vazios!')</script>";
        else if($_GET['error'] == "credentials")
            echo "<script>alert('As suas credenciais estão erradas!')</script>";
    }
?>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <title> Login </title>
        <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway&display=swap">
        <link rel="stylesheet" href="styles.css">
    </head>
    <body>
        <h1 class="title"> Login </h1>
        <?php
            require("header.php");
        ?>
        <form class="form" action="processar-login.php" method="POST">
            <p> Username ou email: </p>
            <input type="text" name="username_email" placeholder="Username ou email">
            <p> Password: </p>
            <input type="password" name="password" placeholder="Password"><br>
            <input type="submit" value="Login">
        </form>
        <?php
            require("footer.php");
        ?>
    </body>
</html>