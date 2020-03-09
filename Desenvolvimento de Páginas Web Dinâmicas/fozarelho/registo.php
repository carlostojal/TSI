<html>
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
        <title> Registo </title>
        <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Raleway&display=swap">
        <link rel="stylesheet" href="styles.css">
    </head>
    <body>
        <h1 class="title"> Registo </h1>
        <form class="form" action="processar-registo.php" method="POST">
            <p> Username: </p>
            <input type="text" name="username" placeholder="Username">
            <p> Password: </p>
            <input type="password" name="password" placeholder="Password">
            <p> Email: </p>
            <input type="text" name="email" placeholder="Email">
            <p> Nome: </p>
            <input type="text" name="name" placeholder="Nome">
            <p> Apelido: </p>
            <input type="text" name="surname" placeholder="Apelido">
            <p> Data de nascimento: </p>
            <input type="date" name="date" placeholder="Data de nascimento"><br><br>
            <input type="submit" value="Registo">
        </form>
    </body>
</html>