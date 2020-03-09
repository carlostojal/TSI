<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <title> Área de utilizador </title>
        <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway&display=swap">
        <link rel="stylesheet" href="styles.css">
    </head>
    <body>
    <?php
    if(session_status() != PHP_SESSION_ACTIVE)
        session_start();
    if(!isset($_SESSION['username'])) {
        header("location: acessonegado.php");
    } else {
    ?>
        <h1 class="title"> Área de Utilizador </h1><br><br>
        <div class="top-opinions">
            <h2 class="title"> Os meus comentários </h2>
    <?php
        require("connection.php");

        $user_name = $_SESSION['username'];
        $sql = "SELECT utilizador.nome, utilizador.apelido, comentario.texto, comentario.data FROM comentario INNER JOIN utilizador ON comentario.username = utilizador.username WHERE comentario.username = '$user_name' ORDER BY comentario.data DESC";
        $res = mysqli_query($con, $sql);
        if(mysqli_num_rows($res) > 0) {
            $data = mysqli_fetch_assoc($res);
            while($data) {
    ?>
        <div>
            <h3> <?php echo $data['nome']." ".$data['apelido']; ?> </h3>
            <h4> <?php echo $data['data']; ?> </h4>
            <div>
                <?php echo $data['texto']; ?>
            </div>
        </div>
    <?php
            }
        } else {
    ?>
        <br><div> Não há comentários. </div>
    <?php
        }
    }
    ?>
    <br><a class="view_all" href="comentar.php"> Comentar </a>
    </body>
</html>