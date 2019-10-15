
<!--

    Copyright (c) Carlos Tojal (carlostojal)
    Foz do Arelho
    estatistica/responder/responder_questionario.php
    github.com/carlostojal/TSI

-->

<!-- Inserção na base de dados -->

<?php
    require_once("../../connection.php");
    if(isset($_POST)) {
        $name = $_POST['name'];
        $age = $_POST['age'];
        $country = $_POST['country'];
        $classification = $_POST['classification'];
        $year = date("Y");

        if($name == "" || $age == "" || $country == "" || $classification == "") {
            header("location: ./?cause=empty+fields");
        }
        else if($age <= 0 || $classification > 120) {
            header("location: ./?cause=age+not+in+range");
        }
        else if($classification < 0 || $classification > 5) {
            header("location: ./?cause=classification+not+in+range");
        }
        else {
            $sql = "INSERT INTO visitantes (name, age, country, classification, year) VALUES ('$name', '$age', '$country', '$classification', '$year')";

            $res = mysqli_query($con, $sql) or die("Error.".mysqli_errno($con));

            if($res)
                header("location: /");
        }
    }
?>
