
<!--
    Copyright (c) Carlos Tojal 2020
    PHP
    logout.php
-->

<?php
    session_start();
    session_destroy();
    header("Location: login.php");
?>