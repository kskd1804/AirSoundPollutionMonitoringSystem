<?php
if(isset($_GET['sensor_value1'])&&isset($_GET['sensor_value2']))
{
$con = mysqli_connect("localhost","root","","arduino");
if(mysqli_connect_errno())
{
	echo 'Connection to database failed!';
}else{
	$air = mysqli_real_escape_string($con,$_GET['sensor_value1']);
	$sound = mysqli_real_escape_string($con,$_GET['sensor_value2']);
	$sql = "INSERT INTO air_sound (air_sensor,sound_sensor) VALUES ('$air','$sound')";
	if(mysqli_query($con,$sql))
	{
		echo 'Data entered successfully';
	}else{
		echo 'Query Unsuccessful!';
	}
}
}
?>