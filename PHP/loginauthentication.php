<?php
   $con=mysqli_connect("localhost","root","","dbpp");

   if (mysqli_connect_errno($con)) {
      echo "Failed to connect to MySQL: " . mysqli_connect_error();
   }
	
   $id = $_POST['id'];
   $password = $_POST['password'];
   $result = mysqli_query($con,"SELECT role FROM login where 
   id='$id' and password='$password'");
   $row = mysqli_fetch_array($result);
   $data = $row[0];
   echo $data;
	
   mysqli_close($con);
?>