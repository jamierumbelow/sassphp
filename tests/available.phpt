--TEST--
Check for sass presence
--SKIPIF--
<?php if (!extension_loaded("sass")) print "skip"; ?>
--FILE--
<?php 
echo "sass extension is available";
?>
--EXPECT--
sass extension is available