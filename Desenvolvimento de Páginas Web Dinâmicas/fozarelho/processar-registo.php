<?php
    $user_name = $_POST['username'];
    $pass_word = $_POST['password'];
    $email = $_POST['email'];
    $name = $_POST['name'];
    $surname = $_POST['surname'];
    $date = $_POST['date'];

    require("connection.php");

    echo $user_name;
    echo $pass_word;

    if($user_name != "" && $pass_word != "" && $email != "" && $name != "" && $surname != "" && $date != 0) {
        $sql = "INSERT INTO utilizador (username, password, email, nome, apelido, data_de_nascimento) VALUES ('$user_name', '".md5($password)."', '$email', '$name', '$surname', '$date')";
        $res = mysqli_query($con, $sql);

        if($res) {
            header("location: index.php");
        } else {
            header("location: registo.php");
        }
    } else {
        header("location: registo.php?error=empty");
    }
?>