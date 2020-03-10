<?php
    if(isset($_GET['error'])) {
        if($_GET['error'] == "empty")
            echo "<script>alert('O campo de comentário está vazio!')</script>";
    }
?>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <title> Comentar </title>
        <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway&display=swap">
        <link rel="stylesheet" href="styles.css">
    </head>
    <body>
        <?php
            if(session_status() != PHP_SESSION_ACTIVE)
            session_start();
            if(!isset($_SESSION['username'])) {
                header("location: acessonegado.php");
            } else {
        ?>
        <h1 class="title"> Comentar </h1>
        <form class="form" action="processar-comentario.php" method="POST">
            <p> Comentario: </p>
            <input type="text" name="comment" placeholder="Comentário"><br>
            <input type="submit" value="Comentar">
        </form>
        <?php
            }
        ?>
    </body>
</html>