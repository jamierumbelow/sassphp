--TEST--
Test Sass is a class
--SKIPIF--
<?php if (!extension_loaded("sass")) print "skip"; ?>
--FILE--
<?php 
if (class_exists('Sass'))
{
	echo 'Sass class exists';
}
?>
--EXPECT--
Sass class exists