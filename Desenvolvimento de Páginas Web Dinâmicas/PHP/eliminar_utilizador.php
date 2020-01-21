<?php
    require("conexao.php");
    session_start();
    if(!isset($_SESSION['username']))
        header("Location: login.php");

    if($_SESSION['role'] == "admin") {
        $sql = "SELECT * FROM utilizadores";
        $res = mysqli_query($con, $sql);
?>

<!DOCTYPE html>
<html>
    <head>
        <meta charset="utf-8">
        <title> Eliminar Utilizador </title>
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css" integrity="sha384-Vkoo8x4CGsO3+Hhxv8T/Q5PaXtkKtu6ug5TOeNV6gBiFeWPGFN9MuhOf23Q9Ifjh" crossorigin="anonymous">
    </head>
    <body>
        <h1> Eliminar Utilizador </h1>
        <?php if(isset($_GET['msg'])) echo $_GET['msg'] ?>
        <table border="2">
            <tr>
                <th> ID de Utilizador </th>
                <th> Nome de Utilizador </th>
                <th> Palavra Passe </th>
                <th> Email </th>
                <th> Privilégios </th>
                <th> Ação </th>
            </tr>
            <?php 
                while($data = mysqli_fetch_array($res)) {
            ?>
            <tr>
                <td> <?php echo $data[0] ?> </td>
                <td> <?php echo $data[1] ?> </td>
                <td> <?php echo $data[2] ?> </td>
                <td> <?php echo $data[3] ?> </td>
                <td> <?php echo $data[4] ?> </td>
                <td><a href="processar_eliminar.php?id=<?php echo $data[0] ?>"> Eliminar </a></td>
            </tr>
            <?php 
                }
            ?>
        </table>
    </body>
</html>

<?php
    } else {
        header("location: menu.php");
    }
?>