<?php

$val = 50;

echo "\"n,\"quad\",\"lin\"\"\n";

for($p=0; $p<100; $p++)
{
	echo "\"$val,";

	$value = trim(shell_exec("/usr/bin/time -f \"%E\" ./quad $val"));
	$value = str_replace('\r', '', str_replace('\n', '', $value));
	$value = str_replace(chr(10), " ", $value); 
	$value = str_replace(chr(13), " ", $value);
	echo "$value,";

	$value = trim(shell_exec("/usr/bin/time -f \"%E\" ./lin $val"));
	$value = str_replace('\r', '', str_replace('\n', '', $value));
	$value = str_replace(chr(10), " ", $value); 
	$value = str_replace(chr(13), " ", $value);
	echo "$value\"\n";
	
	$val += $val * 2;

}


