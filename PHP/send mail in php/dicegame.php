<h1>Roll Em!</h1>

<?php

$roll = rand(1,6);
echo "You rolled a $roll <br><br>";


if ($roll == 1){
  echo "<b>Thats an Ace!!!!</b><br><br>";
}else{
  echo "Thats not and Ace...<br><br>";
}

if ($roll == 1) {
  $binValue  = "001";
}else if ($roll == 2) {
  $binValue = "010";  
}else if ($roll == 3) {
  $binValue = "011";
}else if ($roll == 4) {
  $binValue = "100";
}else if ($roll == 5) {
  $binValue = "101";
}else if ($roll == 6) {
  $binValue = "111";
}else{
  print "I am confused";
}

print "<br>";
print "In binary, thats $binValue";
?>
<br>
Click <button type="button" onClick="window.location.reload();">Refresh</button> to roll another die!

<br>
<p><a href="index.html">return</a></p>


