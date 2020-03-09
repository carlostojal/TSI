<?php
    $user_name = $_POST['username'];
    $password = $_POST['password'];
    $email = $_POST['email'];
    $name = $_POST['name'];
    $surname = $_POST['surname'];
    $date = $_POST['date'];

    require("connection.php");

    $sql = "INSERT INTO utilizador (username, password, email, nome, apelido, data_de_nascimento) VALUES ('$user_name', '".md5($password)."', '$email', '$name', '$surname', '$date')";
    $res = mysqli_query($con, $sql);

    if($res) {
        header("location: index.php");
    } else {
        header("location: registo.php");
    }
?>