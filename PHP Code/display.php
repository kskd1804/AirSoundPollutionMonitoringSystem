<?php
$con = mysqli_connect("localhost","root","","arduino");
if(mysqli_connect_errno())
{
	echo 'Connection to database failed!';
}else{
	$sql = "SELECT air_sensor,sound_sensor FROM air_sound ORDER BY datetime DESC LIMIT 1";
	$query = mysqli_query($con,$sql);
	if($query)
	{
		$row = mysqli_fetch_assoc($query);
		echo '<p><font size="+2" color="#F00">Air: </font><font size="+1" color="#CCC">'.$row['air_sensor'].'</font></p>';
		echo '<p><font size="+2" color="#00F">Sound: </font><font size="+1" color="#CCC">'.$row['sound_sensor'].'</font></p>';
	}else{
		echo 'Query Unsuccessful!';
	}
}
?>