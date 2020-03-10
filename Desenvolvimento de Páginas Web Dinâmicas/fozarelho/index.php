<!DOCTYPE html>

<!--

    Copyright (c) Carlos Tojal (carlostojal)
    Foz do Arelho
    index.php
    github.com/carlostojal/TSI

-->

<!-- Página inicial do site -->

<?php
    require('connection.php');
    if(session_status() != PHP_SESSION_ACTIVE)
        session_start();
?>
<html>
    <head>
        <!--
        <script async src="https://www.googletagmanager.com/gtag/js?id=UA-150584043-1"></script>
        <script>
            window.dataLayer = window.dataLayer || [];
            function gtag(){dataLayer.push(arguments);}
            gtag('js', new Date());
            gtag('config', 'UA-150584043-1');
        </script>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        -->
        <title> Foz do Arelho </title>
        <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway&display=swap">
        <link rel="stylesheet" href="styles.css">
        <!-- Scripts relativos à meteorologia -->
        <script type="text/javascript" src="scripts/weather.js"></script>
        <script type="text/javascript" src="scripts/forecast.js"></script>
    </head>
    <body>
        <h1 class="title"> Foz do Arelho </h1>
        <?php
            require('header.php');
        ?>
        <!-- Contém todo o cabeçalho da página -->
        <header>
            <!-- Contém a meteorologia -->
            <div class="weather_area">
                <h3 class="weather_label">Meteorologia atual:</h3>
                <h3 id="weather">A obter a meteorologia. Por favor aguarde.</h3>
            </div>
        </header>
        <!-- Secção inicial da página que contém a imagem -->
        <section>
            <img class="home_image" src="img/foz1.jpg">
        </section>
        <!-- Conteúdo da página inicial -->
        <article>
            <!-- Texto da página inicial -->
            <div class="home_text">
                Foz do Arelho é uma vila portuguesa do concelho de Caldas da Rainha. <br>
                É conhecida como destino de férias, principalmente por possuir uma praia especialmente peculiar: uma parte da mesma é banhada pelo oceano Atlântico, enquanto que outra pela Lagoa de Óbidos.<br><br>
                Além de proporcionar agradáveis banhos de mar (e de sol), a praia permite disfrutar de uma magnífica paisagem.<br><br>
                O extenso areal da praia da Foz do Arelho é contornado por uma avenida que permite passear, tomar uma bebida, beber um café ou comer um gelado, tanto de dia como de noite, devido aos cafés com esplanada que aí se encontram.<br><br>
                A Lagoa de Óbidos permite a prática de desportos aquáticos como o kitesurf, windsurf ou paddle, e as suas margens compostas por densa vegetação e uma vasta vida selvagem tornam passeios por aí muito agradáveis.<br><br>
                Mas não só de turismo balnear e desportos aquáticos se faz a Foz do Arelho. Além disso existem muitos monumentos e pontos de interesse a visitar. <br>
                Pode ser vista mais informação relativa a este tópico <a href="#o-que-fazer">aqui</a>.
            </div>
            <!-- Secção de onde se localiza-->
            <div class="where_is">
                <h3>Onde se localiza a Foz do Arelho?</h3>
                <div class="where_is_text">
                    A Foz do Arelho localiza-se a aproximadamente:
                    <ul>
                        <li>13 minutos de Caldas da Rainha (8,4 km)</li>
                        <li>1 hora e 10 minutos de Lisboa (96,3 km)</li>
                        <li>2 horas e 10 minutos do Porto (237 km)</li>
                        <li>3 horas e 15 minutos de Faro (348 km)</li>
                    </ul>
                </div>
                <!-- Mapa do Google Maps -->
                <div class="map">
                    <iframe src="https://maps.google.com/maps?q=foz%20do%20arelho&t=&z=11&ie=UTF8&iwloc=&output=embed" frameborder="0" scrolling="no" marginheight="0" marginwidth="0"></iframe>
                </div>
            </div>
            <div class="top_opinions">
                <h2> Comentários </h2>
                <?php
                    $sql = "SELECT utilizador.nome, utilizador.apelido, comentario.texto, comentario.data FROM comentario INNER JOIN utilizador ON comentario.username = utilizador.username ORDER BY comentario.data DESC";
                    $res = mysqli_query($con, $sql);
                    if(mysqli_num_rows($res) > 0) {
                        while($data = mysqli_fetch_assoc($res)) {
                ?>
                <div>
                    <h3> <?php echo $data['nome']." ".$data['apelido']; ?> </h3>
                    <h4> <?php echo $data['data']; ?> </h4>
                    <div>
                        <?php echo $data['texto']; ?>
                    </div>
                </div>
                <br><br>
                <?php
                        }
                    } else {
                ?>
                    <div> Não há comentários. </div>
                <?php
                    }
                    if(!isset($_SESSION['username'])) {
                ?>
                <br><div> Inicie sessão para fazer um comentário. </div>
                <?php
                    } else {
                ?>
                    <br><br><a href="areautilizador.php"> Comentar </a>
                <?php
                    }
                ?>
            </div>
        </article>
        <?php
            require("footer.php");
        ?>
    </body>

    <!-- Obtém meteorogia da API OpenWheatherMap -->
    <script type="text/javascript"> 
        var weather = getWeather();
        var weather_text = getStatus(weather) + ", " + getTemperature(weather) + "°C, vento a " + getWind(weather) + "km/h";

        document.getElementById("weather").innerHTML = weather_text;
    </script>
</html>