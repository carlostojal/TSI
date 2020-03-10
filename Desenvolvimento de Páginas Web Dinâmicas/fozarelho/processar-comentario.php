<?php

    if(session_status() != PHP_SESSION_ACTIVE)
        session_start();

    date_default_timezone_set("Europe/Lisbon");

    $user_name = $_SESSION['username'];
    $comment = $_POST['comment'];
    $date = date("Y-m-d H:m:s");

    require("connection.php");

    if($comment != "") {
        $sql = "INSERT INTO comentario (username, texto, data) VALUES ('$user_name', '$comment', '$date')";
        mysqli_query($con, $sql);
        
        header("location: areautilizador.php");
    } else {
        header("location: comentar.php?error=empty");
    }
?>