<?php
        echo "hello \n";
        if(isset($_POST['val']))
        {
                $value = $_POST['val'];
                echo $value;
                // system("echo ".(int)$value." > /dev/ttyAMA0");
        }
?>