<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Document</title>
</head>
<body>
<?php
$servername = "localhost";
$username = "pakpoom";
$password = "";
$dbname = "pakpoom";

// Create connection
$conn = new mysqli($servername, $username, $password, $dbname);
    
// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
} 

$sql = "SELECT name, phonenumber FROM iot";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // output data of each row
    while($row = $result->fetch_assoc()) {
        echo "ชื่อ: " . $row["name"]. " - เบอร์โทร: " . $row["phonenumber"]. "<br>";
    }
} else {
    echo "0 results";
}
$conn->close();
?>
</body>
</html>