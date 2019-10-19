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
        else if($row['country'] == "Espanha" || $row['country'] == "Spain")
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
            <title> Statistic - Foz do Arelho </title>
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
                <h1 class="title"> Statistic </h1>

                <!-- Itens do menu -->
                <nav class="menu">
                    <a class="menu_items" href="../en"> HOME </a>
                    <a class="menu_items" href="../where-to-stay"> WHERE TO STAY </a>
                    <a class="menu_items" href="../what-to-do"> WHAT TO DO </a>
                    <a class="menu_items" href="../forecast"> WEATHER FORECAST </a>
                    <a class="menu_items" href="."> STATISTIC </a> 
                    <a class="menu_items" href="../contacts"> CONTACTS </a>
                    <a class="menu_items" href="../estatistica"> PT </a>
                </nav>
            </div>
        </header>
        <section>
            <div class="stats_introduction">
                It is also interesting to know the opinion of visitors from Foz do Arelho, how old they are, and where they come from.<br>
                Below is this information, in real time.<br>
                If you have recently visited Foz do Arelho, or are currently visiting, please also give your
                contribution by taking <a href="questionnaire"> this </a> questionnaire.
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
                        echo "<a class='view_all' href='view-all'> View all </a>";
                        echo "</div>"
                ?>
            <div class="age_stats">
                <h3> How old are Foz do Arelho visitors? * </h3>
                <table border="2">
                    <tr>
                        <th> Less than 18 years old </th>
                        <td> <?php echo number_format(($n_menos_dezoito/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Between 18 and 35 years old </th>
                        <td> <?php echo number_format(($n_dezoito_trintacinco/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Between 35 and 50 years old </th>
                        <td> <?php echo number_format(($n_trintacinco_cinquenta/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Between 50 and 70 years old </th>
                        <td> <?php echo number_format(($n_cinquenta_setenta/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> More than 70 years old </th>
                        <td> <?php echo number_format(($n_setenta_mais/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                </table>
            </div><br>
            <div class="provenence_stats">
                <h3> Where are they from? * </h3>
                <table border="2">
                    <tr>
                        <th> Portugal </th>
                        <td> <?php echo number_format(($n_portugal/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Spain </th>
                        <td> <?php echo number_format(($n_espanha/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                    <tr>
                        <th> Other </th>
                        <td> <?php echo number_format(($n_outros/$total) * 100, 2, '.', '') ?>% </td>
                    </tr>
                </table>
            </div>
            <p class="stats_legend"> * Out of <?php echo mysqli_num_rows($res); if(mysqli_num_rows($res) == 1) echo " respond"; else echo " responds"?>. </p>
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
