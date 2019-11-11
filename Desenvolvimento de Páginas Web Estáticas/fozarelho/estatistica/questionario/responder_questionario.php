
<!--

    Copyright (c) Carlos Tojal (carlostojal)
    Foz do Arelho
    statistic/questionnaire/respond_questionnaire.php
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
        $opinion = $_POST['opinion'];
        $divulgation = $_POST['divulgation'];
        $year = date("Y");

        if($divulgation == "on")
            $divulgation = 1;
        else
            $divulgation = 0;

        if($name == "" || $age == "" || $country == "" || $classification == "" || $opinion == "") {
            header("location: ./?cause=empty+fields");
        }
        else if($age <= 0 || $classification > 120) {
            header("location: ./?cause=age+not+in+range");
        }
        else if($classification <= 0 || $classification > 5) {
            header("location: ./?cause=classification+not+in+range");
        }
        else {
            $sql = "INSERT INTO visitantes (name, age, country, classification, opinion, divulgation, year) VALUES ('$name', '$age', '$country', '$classification', '$opinion', '$divulgation', '$year')";

            $res = mysqli_query($con, $sql) or die("Error.".mysqli_errno($con));
        }
    }

    header("location: ../");
?>
