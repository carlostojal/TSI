<?php
    $username_email = $_POST['username_email'];
    $pass_word = $_POST['password'];

    require("connection.php");

    $sql = "SELECT * FROM utilizador WHERE (username = '$username_email' OR email = '$username_email') AND password = '".md5($pass_word)."'";
    $res = mysqli_query($con, $sql);

    if($username_email != "" && $pass_word != "") {
        if(mysqli_num_rows($res) == 1) {
            if(session_status() != PHP_SESSION_ACTIVE)
                session_start();
            $data = mysqli_fetch_assoc($res);
            $_SESSION['username'] = $data['username'];
            header("location: index.php");
        } else {
            header("location: login.php?error=credentials");
        }
    } else {
        header("location: login.php?error=empty");
    }
?>