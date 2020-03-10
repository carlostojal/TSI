<?php
    if(session_status() != PHP_SESSION_ACTIVE)
        session_start();
?>
<nav class="menu">
<a class="menu_items" href="index.php"> INÍCIO </a>
<?php
    if(!isset($_SESSION['username'])) {
?>
    <a class="menu_items" href="login.php"> LOGIN </a>
    <a class="menu_items" href="registo.php"> REGISTO </a>
<?php
    } else {
        require("connection.php");

        $user_name = $_SESSION['username'];

        $sql = "SELECT * FROM utilizador WHERE username = '$user_name'";
        $res = mysqli_query($con, $sql);
        $data = mysqli_fetch_assoc($res);
        $name = strtoupper($data['nome']." ".$data['apelido']);
?>
    <a class="menu_items" href="areautilizador.php"> ÁREA DE UTILIZADOR </a>
    <a class="menu_items" href="logout.php"> WELCOME, <?php echo $name ?> (LOGOUT) </a>
<?php
    }
?>
</nav>