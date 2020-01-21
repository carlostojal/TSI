
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    processar_eliminar.php
-->

<?php
    include("conexao.php");
    session_start();
    if(isset($_SESSION['username'])) {
        // Só permite eliminar o utilizador se for administrador
        if($_SESSION['role'] == "admin") {
            // Elimina o utilizador com o id passado por GET
            if(isset($_GET['id'])) {
                $id = $_GET['id'];
                $sql = "DELETE FROM utilizadores WHERE id_utilizador = $id";
                $res = mysqli_query($con, $sql);
                if($res)
                    header("Location: eliminar_utilizador.php?msg=Utilizador+eliminado+com+sucesso");
            } else {
                header("Location: menu.php");
            }
        } else {
            header("Location: menu.php");
        }
    } else {
        header("Location: login.php");
    }
?>