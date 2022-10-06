<?php 
require './vendor/autoload.php';
use Mailgun\Mailgun;

#token
$mgClient =  Mailgun::create('');

#domian
$domain = "";

#email from
$from = "";

#email to
$to = "";

# Make the call to the client.
$result = $mgClient->messages()->send($domain, array(
	'from'	=> $from,
	'to'	=> $to,
	'subject' => 'Hello',
	'text'	=> 'Testing some Mailgun awesomness!'
));

?>