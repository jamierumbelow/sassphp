--TEST--
Test Sass is instantiatable
--SKIPIF--
<?php if (!extension_loaded("sass")) print "skip"; ?>
--FILE--
<?php 
$sass = new Sass();

if ($sass)
{
	echo get_class($sass);
}
?>
--EXPECT--
Sass