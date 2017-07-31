<html>
<head>
<title>Air and Sound Pollution Monitering System</title>
<script type="text/javascript" src="js/jquery.js"></script>
<script type="text/javascript">
	
	$(document).ready(function(e) {
		setInterval(function(){
		$("#sensor").load("display.php");
		},1000);
    });
</script>
</head>
<body>
<h1>Air and Sound Pollution Monitering System</h1>
<div id="sensor">

</div>
</body>
</html>