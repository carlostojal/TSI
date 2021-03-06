<!DOCTYPE html>

<!--

    Copyright (c) Carlos Tojal (carlostojal)
    Foz do Arelho
    estatistica/questionario/index.php
    github.com/carlostojal/TSI

-->

<!-- Responder ao formulário -->

<html>
    <head>
        <!-- Scripts Google Analytics-->
        <script async src="https://www.googletagmanager.com/gtag/js?id=UA-150584043-1"></script>
        <script>
            window.dataLayer = window.dataLayer || [];
            function gtag(){dataLayer.push(arguments);}
            gtag('js', new Date());
            gtag('config', 'UA-150584043-1');
        </script>
            <meta charset="UTF-8">
            <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
            <title> Questionário - Foz do Arelho </title>
            <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway&display=swap">
            <link rel="stylesheet" href="../../styles.css">
            <!-- Bootstrap -->
            <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.1.3/css/bootstrap.min.css" integrity="sha384-MCw98/SFnGE8fJT3GXwEOngsV7Zt27NXFoaoApmYm81iuXoPkFOJwJ8ERdknLPMO" crossorigin="anonymous">
            <!-- Script Vue.js -->
            <script src="https://cdn.jsdelivr.net/npm/vue/dist/vue.js"></script>
    </head>
    <body>
        <!-- Contém todo o cabeçalho da página -->
        <header>
            <div class="title_header">
                <!-- Título grande -->
                <h1 class="title"> Questionário </h1>

                <!-- Itens do menu -->
                <nav class="menu">
                    <a class="menu_items" href="../../"> INÍCIO </a>
                    <a class="menu_items" href="../../onde-ficar"> ONDE FICAR </a>
                    <a class="menu_items" href="../../o-que-fazer">O QUE FAZER </a>
                    <a class="menu_items" href="../../previsao"> PREVISÃO METEOROLÓGICA </a>
                    <a class="menu_items" href=".."> ESTATÍSTICA </a>
                    <a class="menu_items" href="../../contatos"> CONTATOS </a>
                    <a class="menu_items" href="../../statistic/questionnaire"> EN </a>
                </nav>
            </div>
        </header>
        <section>
            <?php
                if(isset($_GET['cause'])) {
                    echo "<div class='form_fail'>\n";
                    $cause = $_GET['cause'];
                    if($cause == "empty fields")
                        echo "\t\t\t\tForam deixados campos em branco.\n";
                    else if($cause == "age not in range")
                        echo "\t\t\t\tO valor da idade não é válido.\n";
                    else if($cause == "classification not in range")
                        echo "\t\t\t\tA classificação é necessariamente um valor entre 1 e 5.\n";
                    echo "\t\t\t</div><br>\n";
                }
            ?>
            <form class="form" method="post" action="responder_questionario.php">
                <input type="text" name="name" placeholder="Nome" id="nome"><br>
                <input type="number" name="age" placeholder="Idade" id="age"><br>
                <select name="country" id="country">
                    <option disabled selected>País</option>
                    <option value="Portugal">Portugal</option>
                    <option value="África do Sul">África do Sul</option>
                    <option value="Albânia">Albânia</option>
                    <option value="Alemanha">Alemanha</option>
                    <option value="Andorra">Andorra</option>
                    <option value="Angola">Angola</option>
                    <option value="Anguilla">Anguilla</option>
                    <option value="Antigua">Antigua</option>
                    <option value="Arábia Saudita">Arábia Saudita</option>
                    <option value="Argentina">Argentina</option>
                    <option value="Armênia">Armênia</option>
                    <option value="Aruba">Aruba</option>
                    <option value="Austrália">Austrália</option>
                    <option value="Áustria">Áustria</option>
                    <option value="Azerbaijão">Azerbaijão</option>
                    <option value="Bahamas">Bahamas</option>
                    <option value="Bahrein">Bahrein</option>
                    <option value="Bangladesh">Bangladesh</option>
                    <option value="Barbados">Barbados</option>
                    <option value="Bélgica">Bélgica</option>
                    <option value="Benin">Benin</option>
                    <option value="Bermudas">Bermudas</option>
                    <option value="Botsuana">Botsuana</option>
                    <option value="Brasil">Brasil</option>
                    <option value="Brunei">Brunei</option>
                    <option value="Bulgária">Bulgária</option>
                    <option value="Burkina Fasso">Burkina Fasso</option>
                    <option value="botão">botão</option>
                    <option value="Cabo Verde">Cabo Verde</option>
                    <option value="Camarões">Camarões</option>
                    <option value="Camboja">Camboja</option>
                    <option value="Canadá">Canadá</option>
                    <option value="Cazaquistão">Cazaquistão</option>
                    <option value="Chade">Chade</option>
                    <option value="Chile">Chile</option>
                    <option value="China">China</option>
                    <option value="Cidade do Vaticano">Cidade do Vaticano</option>
                    <option value="Colômbia">Colômbia</option>
                    <option value="Congo">Congo</option>
                    <option value="Coréia do Sul">Coréia do Sul</option>
                    <option value="Costa do Marfim">Costa do Marfim</option>
                    <option value="Costa Rica">Costa Rica</option>
                    <option value="Croácia">Croácia</option>
                    <option value="Dinamarca">Dinamarca</option>
                    <option value="Djibuti">Djibuti</option>
                    <option value="Dominica">Dominica</option>
                    <option value="EUA">EUA</option>
                    <option value="Egito">Egito</option>
                    <option value="El Salvador">El Salvador</option>
                    <option value="Emirados Árabes">Emirados Árabes</option>
                    <option value="Equador">Equador</option>
                    <option value="Eritréia">Eritréia</option>
                    <option value="Escócia">Escócia</option>
                    <option value="Eslováquia">Eslováquia</option>
                    <option value="Eslovênia">Eslovênia</option>
                    <option value="Espanha">Espanha</option>
                    <option value="Estônia">Estônia</option>
                    <option value="Etiópia">Etiópia</option>
                    <option value="Fiji">Fiji</option>
                    <option value="Filipinas">Filipinas</option>
                    <option value="Finlândia">Finlândia</option>
                    <option value="França">França</option>
                    <option value="Gabão">Gabão</option>
                    <option value="Gâmbia">Gâmbia</option>
                    <option value="Gana">Gana</option>
                    <option value="Geórgia">Geórgia</option>
                    <option value="Gibraltar">Gibraltar</option>
                    <option value="Granada">Granada</option>
                    <option value="Grécia">Grécia</option>
                    <option value="Guadalupe">Guadalupe</option>
                    <option value="Guam">Guam</option>
                    <option value="Guatemala">Guatemala</option>
                    <option value="Guiana">Guiana</option>
                    <option value="Guiana Francesa">Guiana Francesa</option>
                    <option value="Guiné-bissau">Guiné-bissau</option>
                    <option value="Haiti">Haiti</option>
                    <option value="Holanda">Holanda</option>
                    <option value="Honduras">Honduras</option>
                    <option value="Hong Kong">Hong Kong</option>
                    <option value="Hungria">Hungria</option>
                    <option value="Iêmen">Iêmen</option>
                    <option value="Ilhas Cayman">Ilhas Cayman</option>
                    <option value="Ilhas Cook">Ilhas Cook</option>
                    <option value="Ilhas Curaçao">Ilhas Curaçao</option>
                    <option value="Ilhas Marshall">Ilhas Marshall</option>
                    <option value="Ilhas Turks & Caicos">Ilhas Turks & Caicos</option>
                    <option value="Ilhas Virgens (brit.)">Ilhas Virgens (brit.)</option>
                    <option value="Ilhas Virgens(amer.)">Ilhas Virgens(amer.)</option>
                    <option value="Ilhas Wallis e Futuna">Ilhas Wallis e Futuna</option>
                    <option value="Índia">Índia</option>
                    <option value="Indonésia">Indonésia</option>
                    <option value="Inglaterra">Inglaterra</option>
                    <option value="Irlanda">Irlanda</option>
                    <option value="Islândia">Islândia</option>
                    <option value="Israel">Israel</option>
                    <option value="Itália">Itália</option>
                    <option value="Jamaica">Jamaica</option>
                    <option value="Japão">Japão</option>
                    <option value="Jordânia">Jordânia</option>
                    <option value="Kuwait">Kuwait</option>
                    <option value="Latvia">Latvia</option>
                    <option value="Líbano">Líbano</option>
                    <option value="Liechtenstein">Liechtenstein</option>
                    <option value="Lituânia">Lituânia</option>
                    <option value="Luxemburgo">Luxemburgo</option>
                    <option value="Macau">Macau</option>
                    <option value="Macedônia">Macedônia</option>
                    <option value="Madagascar">Madagascar</option>
                    <option value="Malásia">Malásia</option>
                    <option value="Malaui">Malaui</option>
                    <option value="Mali">Mali</option>
                    <option value="Malta">Malta</option>
                    <option value="Marrocos">Marrocos</option>
                    <option value="Martinica">Martinica</option>
                    <option value="Mauritânia">Mauritânia</option>
                    <option value="Mauritius">Mauritius</option>
                    <option value="México">México</option>
                    <option value="Moldova">Moldova</option>
                    <option value="Mônaco">Mônaco</option>
                    <option value="Montserrat">Montserrat</option>
                    <option value="Nepal">Nepal</option>
                    <option value="Nicarágua">Nicarágua</option>
                    <option value="Niger">Niger</option>
                    <option value="Nigéria">Nigéria</option>
                    <option value="Noruega">Noruega</option>
                    <option value="Nova Caledônia">Nova Caledônia</option>
                    <option value="Nova Zelândia">Nova Zelândia</option>
                    <option value="Omã">Omã</option>
                    <option value="Palau">Palau</option>
                    <option value="Panamá">Panamá</option>
                    <option value="Papua-nova Guiné">Papua-nova Guiné</option>
                    <option value="Paquistão">Paquistão</option>
                    <option value="Peru">Peru</option>
                    <option value="Polinésia Francesa">Polinésia Francesa</option>
                    <option value="Polónia">Polónia</option>
                    <option value="Porto Rico">Porto Rico</option>
                    <option value="Qatar">Qatar</option>
                    <option value="Quênia">Quênia</option>
                    <option value="Rep. Dominicana">Rep. Dominicana</option>
                    <option value="Rep. Tcheca">Rep. Tcheca</option>
                    <option value="Reunion">Reunion</option>
                    <option value="Romênia">Romênia</option>
                    <option value="Ruanda">Ruanda</option>
                    <option value="Rússia">Rússia</option>
                    <option value="Saipan">Saipan</option>
                    <option value="Samoa Americana">Samoa Americana</option>
                    <option value="Senegal">Senegal</option>
                    <option value="Serra Leone">Serra Leone</option>
                    <option value="Seychelles">Seychelles</option>
                    <option value="Singapura">Singapura</option>
                    <option value="Síria">Síria</option>
                    <option value="Sri Lanka">Sri Lanka</option>
                    <option value="St. Kitts & Nevis">St. Kitts & Nevis</option>
                    <option value="St. Lúcia">St. Lúcia</option>
                    <option value="St. Vincent">St. Vincent</option>
                    <option value="Sudão">Sudão</option>
                    <option value="Suécia">Suécia</option>
                    <option value="Suiça">Suiça</option>
                    <option value="Suriname">Suriname</option>
                    <option value="Tailândia">Tailândia</option>
                    <option value="Taiwan">Taiwan</option>
                    <option value="Tanzânia">Tanzânia</option>
                    <option value="Togo">Togo</option>
                    <option value="Trinidad & Tobago">Trinidad & Tobago</option>
                    <option value="Tunísia">Tunísia</option>
                    <option value="Turquia">Turquia</option>
                    <option value="Ucrânia">Ucrânia</option>
                    <option value="Uganda">Uganda</option>
                    <option value="Uruguai">Uruguai</option>
                    <option value="Venezuela">Venezuela</option>
                    <option value="Vietname">Vietname</option>
                    <option value="Zaire">Zaire</option>
                    <option value="Zâmbia">Zâmbia</option>
                    <option value="Zimbábue">Zimbábue</option>
                </select><br>
                <input type="number" name="classification" placeholder="Classificação de 1 a 5" id="classification"><br>
                <textarea class="opinion" name="opinion" rows="7" placeholder="Dê uma curta opinião acerca da sua visita, pontos fortes e fracos. Sinta-se à vontade." id="opinion"></textarea><br>
                <input class="checkbox" type="checkbox" name="divulgation" id="divulgation" checked> Aceita a divulgação dos seus dados dentro deste website (o seu comentário será público)
                <br><br>
                <input class="respond" type="submit" value="Respond">
                <br><br>
                <p>Ao responder, aceita a utilização dos seus dados para fins estatísticos dentro deste website. A segurança e privacidade dos mesmos não pode ser completamente assegurada.</p>
            </form>
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
