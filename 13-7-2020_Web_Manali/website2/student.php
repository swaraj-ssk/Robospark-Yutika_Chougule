<?php
session_start();
include('db1.php');
if(isset($_POST['submit']))
{
    $stud_id=$_POST['stud_id'];
    $query="SELECT * FROM `student` WHERE `stud_id`='$stud_id'";
    $run= mysqli_query($con,$query);
    $row= mysqli_num_rows($run);

    if($row == 1)
    {
        $_SESSION['stud_id']=$stud_id;

        $stud_row= mysqli_fetch_assoc($run);

        // echo "<h3>","<b>","STUDENT DETAILS: ","</b>","</h3>";
        //echo "<br>";
        //echo "Welcome  ".$stud_row['stud_name'];
        //echo "<br> ID: " .$stud_row['stud_id'];
        //echo "<br> BRANCH: " .$stud_row['stud_branch'];
        //echo "<br> CGPA: " .$stud_row['stud_cgpa'];
        
        $stud_id= $stud_row['stud_id'];
        $stud_name=$stud_row['stud_name'];
        $stud_branch=$stud_row['stud_branch'];
        $stud_cgpa=$stud_row['stud_cgpa'];

    }
   
}
?>
<html lang="en">
    <head>
    <meta charset="UTF-8"/>
    <title>STUDENT INFO </title>
    <link rel="stylesheet" href="student.css">
    </head>
    <body>
    
    <div class="info-page">
        <?php if($row==1){
            echo "<h2>","<b>","Welcome ".$stud_name ," !" ,"</b>","</h2>";
            echo "<h3>","<b>","STUDENT DETAILS: ","</b>","</h3>";
            echo "ID: ".$stud_id;
            echo "<br>", "Name: ".$stud_name;
            echo "<br>", "Branch: ".$stud_branch;
            echo "<br>", "CGPA: ".$stud_cgpa;
         }
         else
         {
             echo "<h4>","STUDENT_ID NOT FOUND","</h4>";
         }
         ?>
    </div>
    </body>
</html>