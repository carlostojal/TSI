<?php
    if(session_status() != PHP_SESSION_ACTIVE)
        session_start();

    require("connection.php");
    
    $sql = "SELECT * FROM comentario INNER JOIN utilizador ON comentario.username = utilizador.username WHERE comentario.id = '".$_GET['id']."' AND utilizador.username = '".$_SESSION['username']."'";
    $res = mysqli_query($con, $sql);

    if(mysqli_num_rows($res) == 1) {
        $sql = "DELETE FROM comentario WHERE id = '".$_GET['id']."'";
        mysqli_query($con, $sql);
        header("location: areautilizador.php");
    }
?>
