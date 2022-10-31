<?php
clear();
print(coloredStr(" Simple Calculator\n\n", "cyan"));

angka1:
print(coloredStr(" Your first number goes here: ", "green"). "\n ~> ");
$angka1 = trim(fgets(STDIN));
if(!is_numeric($angka1))
{
	print(coloredStr(" Please enter a valid number\n\n", "red"));
	goto angka1;
}
print("\n");

operation:
print(coloredStr(" a. (+), b. (-), c. (*), d. (/)\n", "purple"));
print(coloredStr(" What operation would you choose: ", "green"). "\n ~> ");
$jenis = trim(fgets(STDIN));
if(empty($jenis))
{
	print(coloredStr(" Please input your operation\n\n", "red"));
	goto angka1;
}
print("\n");

angka2:
print(coloredStr(" Your second number goes here: ", "green"). "\n ~> ");
$angka2 = trim(fgets(STDIN));
if(!is_numeric($angka2))
{
	print(coloredStr(" Please enter a valid number\n\n", "red"));
	goto angka2;
}
print("\n");

$result = calculate($angka1, $angka2, $jenis);
print(coloredStr(" The result is: ".$result, "cyan"));
fgets(STDIN);
clear();

/* Function * -/- * Don't you try to change everything below here */

function clear()
{
  return print(chr(27) . chr(91) . 'H' . chr(27) . chr(91) . 'J'."\n"); //^[H^[J
}

function calculate($angka1, $angka2, $jenis)
{
	if($jenis == "a") return $angka1 + $angka2;
	elseif($jenis == "b") return $angka1 - $angka2;
	elseif($jenis == "c") return $angka1 * $angka2;
	elseif($jenis == "d") return $angka1 / $angka2;
	else return coloredStr("I think you input wrong operation, please try again\n\n", "red");
}

function coloredStr($string, $color)
{
    $array = [
        "green" => "1;32",
        "red" => "1;31",
        "yellow" => "1;33",
        "purple" => "1;35",
        "cyan" => "1;36",
        "gray" => "0;37",
    ];
    $text = "\033[" . $array[$color] . "m" . $string . "\033[0m";
    return $text;
}
