<?php
    require_once("../../connection.php");
    if(isset($_GET)) {
        $name = $_GET['name'];
        $age = $_GET['age'];
        $country = $_GET['country'];
        $classification = $_GET['classification'];
        $opinion = $_GET['opinion'];
        $divulgation = $_GET['divulgation'];
        $year = date("Y");

        if($divulgation == "on")
            $divulgation = 1;
        else
            $divulgation = 0;

        $sql = "INSERT INTO visitantes (name, age, country, classification, opinion, divulgation, year) VALUES ('$name', '$age', '$country', '$classification', '$opinion', '$divulgation', '$year')";

        $res = mysqli_query($con, $sql) or die("Erro.".mysqli_errno($con));

        echo "success";
    }
?>
