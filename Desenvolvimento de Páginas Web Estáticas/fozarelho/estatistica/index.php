<!DOCTYPE html>

<!--

    Copyright (c) Carlos Tojal (carlostojal)
    Foz do Arelho
    estatistica/index.php
    github.com/carlostojal/TSI

-->

<!-- Estatística dos turistas -->

<html>
    <head>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
            <title> Estatística - Foz do Arelho </title>
            <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway&display=swap">
            <link rel="stylesheet" href="../styles.css">
            <!-- Bootstrap -->
            <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
            <!-- Scripts JS relativos à meteorologia -->
            <script type="text/javascript" src="../scripts/weather.js"></script>
            <script type="text/javascript" src="../scripts/forecast.js"></script>
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
            <div class="age_stats">
                <h3> Que idade têm os visitantes da Foz do Arelho? </h3>
                <table border="2">
                    <tr>
                        <th> Menos de 18 anos </th>
                        <td> x% </td>
                    </tr>
                    <tr>
                        <th> Entre 18 e 35 anos </th>
                        <td> x% </td>
                    </tr>
                    <tr>
                        <th> Entre 35 e 50 anos </th>
                        <td> x% </td>
                    </tr>
                    <tr>
                        <th> Entre 50 e 70 anos </th>
                        <td> x% </td>
                    </tr>
                    <tr>
                        <th> Mais de 70 anos </th>
                        <td> x% </td>
                    </tr>
                </table>
            </div>
            <div class="provenence_stats">
                <h3> De onde vêm? </h3>
                <table border="2">
                    <tr>
                        <th> Portugal </th>
                        <td> x% </td>
                    </tr>
                    <tr>
                        <th> Espanha </th>
                        <td> x% </td>
                    </tr>
                    <tr>
                        <th> Outros </th>
                        <td> x% </td>
                    </tr>
                </table>
            </div>
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
