<!DOCTYPE html>

<!--

    Copyright (c) Carlos Tojal (carlostojal)
    Foz do Arelho
    estatistica/ver-todos/index.php
    github.com/carlostojal/TSI

-->

<!-- Comentários dos visitantes -->

<?php
    require_once("../../connection.php");

    $sql = "SELECT * FROM visitantes WHERE divulgation = '1' ORDER BY classification DESC";
    $res = mysqli_query($con, $sql);
?>

<html>
    <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
            <title> Comentários - Foz do Arelho </title>
            <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway&display=swap">
            <link rel="stylesheet" href="../../styles.css">
            <!-- Bootstrap -->
            <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
    </head>
    <body>
        <!-- Contém todo o cabeçalho da página -->
        <header>
            <div class="title_header">
                <!-- Título grande -->
                <h1 class="title"> Comentários </h1>

                <!-- Itens do menu -->
                <nav class="menu">
                    <a class="menu_items" href="../"> INÍCIO </a>
                    <a class="menu_items" href="../onde-ficar"> ONDE FICAR </a>
                    <a class="menu_items" href="../o-que-fazer">O QUE FAZER </a>
                    <a class="menu_items" href="../previsao"> PREVISÃO METEOROLÓGICA </a>
                    <a class="menu_items" href=".."> ESTATÍSTICA </a>
                    <a class="menu_items" href="../contatos"> CONTATOS </a>
                    <a class="menu_items" href="../"> EN </a>
                </nav>
            </div>
        </header>
        <article>
        <?php
            if(mysqli_num_rows($res) > 0)
                echo "<div class='top_opinions'>";
            while($respostas = mysqli_fetch_assoc($res)) {
        ?>
        <h5><i> <?php echo "\"".$respostas['opinion']."\"" ?> </i></h5>
        <p> <?php echo $respostas['name'].", ".$respostas['year']." (avaliou em ".$respostas['classification']."/5)" ?> </p>
        <?php
            echo "<br>";
            }
            if(mysqli_num_rows($res) > 0)
                echo "</div>"
        ?>
        </article>
        <!-- Fundo da página que contém dados do desenvolvedor -->
        <footer>
            Desenvolvido por Carlos Tojal<br>
            <div class="contacts">
                GitHub: <a href="https://github.com/carlostojal" target="blank">carlostojal</a><br>
                Email: <a href="mailto:carlos.tojal@hotmail.com" target="blank">carlos.tojal@hotmail.com</a>
            </div><br>
            <div class="copyright">Copyright © Carlos Tojal (2019)</div>
        </footer>
    </body>
</html>
