<?php
    include("conexao.php");

    if(isset($_GET['id'])) {
        $id = $_GET['id'];
        $sql = "DELETE FROM utilizadores WHERE id_utilizador = $id";
        $res = mysqli_query($con, $sql);
        if($res)
            header("Location: eliminar_utilizador.php?msg=Utilizador+eliminado+com+sucesso");
    } else {
        header("Location: menu.php");
    }
?>