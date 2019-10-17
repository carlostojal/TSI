<!DOCTYPE html>

<!--

    Copyright (c) Carlos Tojal (carlostojal)
    Foz do Arelho
    estatistica/index.php
    github.com/carlostojal/TSI

-->

<!-- Estatística dos visitantes -->

<?php
    require_once("../connection.php");

    $total = 1;
    $n_menos_dezoito = 0;
    $n_dezoito_trintacinco = 0;
    $n_trintacinco_cinquenta = 0;
    $n_cinquenta_setenta = 0;
    $n_setenta_mais = 0;

    $n_portugal = 0;
    $n_espanha = 0;
    $n_outros = 0;

    $sql = "SELECT * FROM visitantes";
    $res = mysqli_query($con, $sql);
    $total = mysqli_num_rows($res);

    while($row = mysqli_fetch_assoc($res)) {
        if($row['age'] < 18)
            $n_menos_dezoito++;
        else if($row['age'] >= 18 && $row['age'] < 35)
            $n_dezoito_trintacinco++;
        else if($row['age'] >= 35 && $row['age'] < 50)
            $n_trintacinco_cinquenta++;
        else if($row['age'] >= 50 && $row['age'] < 70)
            $n_cinquenta_setenta++;
        else
            $n_setenta_mais++;

        if($row['country'] == "Portugal")
            $n_portugal++;
        else if($row['country'] == "Espanha")
            $n_espanha++;
        else
            $n_outros++;
    }

    $sql = "SELECT * FROM visitantes WHERE divulgation = '1' ORDER BY classification DESC";
    $res1 = mysqli_query($con, $sql);
?>

<html>
    <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
            <title> Estatística - Foz do Arelho </title>
            <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway&display=swap">
            <link rel="stylesheet" href="../styles.css">
            <!-- Bootstrap -->
            <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
    </head>
    <body>
        <!-- Contém todo o cabeçalho da página -->
        <header>
            <div class="title_header">
                <!-- Título grande -->
                <h1 class="title"> Estatística </h1>

                <!-- Itens do menu -->
                <nav class="menu">
                    <a class="menu_items" href="../"> INÍCIO </a>
                    <a class="menu_items" href="../onde-ficar"> ONDE FICAR </a>
                    <a class="menu_items" href="../o-que-fazer">O QUE FAZER </a>
                    <a class="menu_items" href="../previsao"> PREVISÃO METEOROLÓGICA </a>
                    <a class="menu_items" href="../contatos"> CONTATOS </a>
                    <a class="menu_items" href="../"> EN </a>
                </nav>
            </div>
        </header>
        <section>
            <div class="stats_introduction">
                É interessante também saber a opinião dos visitantes da Foz do Arelho, que idade têm, e de onde vêm.<br>
                Abaixo está essa informação, em tempo real.<br>
                Se visitou recentemente a Foz do Arelho, ou está atualmente a visitar, dê também por favor o seu
                contributo, respondendo a <a href="questionario">este</a> questionário.
            </div>
                <?php
                    if($total == 0) $total = 1;
                    if(mysqli_num_rows($res1) > 0)
                        echo "<div class='top_opinions'>";
                    $count = 0;
                    while(($melhores = mysqli_fetch_assoc($res1)) && $count < 3) {
                        if($melhores['classification'] >= 4) {
                            $count++;
                ?>
                <h5><i> <?php echo "\"".$melhores['opinion']."\"" ?> </i></h5>
                <p> <?php echo $melhores['name'].", ".$melhores['year']." (avaliou em ".$melhores['classification']."/5)" ?> </p>
                <?php
                            echo "<br>";
                        }
                    }
                    if(mysqli_num_rows($res1) > 0)
                        echo "<a class='view_all' href='ver-todos'> Ver todos os comentários </a>";
                        echo "</div>"
                ?>
            <div class="age_stats">
                <h3> Que idade têm os visitantes da Foz do Arelho? * </h3>
                <table border="2">
                    <tr>
                        <th> Menos de 18 anos </th>
                        <td> <?php echo number_format(($n_menos_dezoito/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Entre 18 e 35 anos </th>
                        <td> <?php echo number_format(($n_dezoito_trintacinco/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Entre 35 e 50 anos </th>
                        <td> <?php echo number_format(($n_trintacinco_cinquenta/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Entre 50 e 70 anos </th>
                        <td> <?php echo number_format(($n_cinquenta_setenta/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Mais de 70 anos </th>
                        <td> <?php echo number_format(($n_setenta_mais/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                </table>
            </div><br>
            <div class="provenence_stats">
                <h3> De onde vêm? * </h3>
                <table border="2">
                    <tr>
                        <th> Portugal </th>
                        <td> <?php echo number_format(($n_portugal/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Espanha </th>
                        <td> <?php echo number_format(($n_espanha/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Outros </th>
                        <td> <?php echo number_format(($n_outros/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                </table>
            </div>
            <p class="stats_legend"> * Num total de <?php echo mysqli_num_rows($res); if(mysqli_num_rows($res) == 1) echo " resposta"; else echo " respostas"?> ao questionário. </p>
        </section>
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
