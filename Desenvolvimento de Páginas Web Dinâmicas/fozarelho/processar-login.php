<?php
    $username_email = $_POST['username_email'];
    $password = $_POST['password'];

    require("connection.php");

    $sql = "SELECT * FROM utilizador WHERE (username = '$username_email' OR email = '$username_email') AND password = '".md5($password)."'";
    $res = mysqli_query($con, $sql);

    if(mysqli_num_rows($res) == 1) {
        if(session_status() != PHP_SESSION_ACTIVE)
            session_start();
        $data = mysqli_fetch_assoc($res);
        $_SESSION['username'] = $data['username'];
        header("location: index.php");
    } else {
        header("location: login.php");
    }
?>