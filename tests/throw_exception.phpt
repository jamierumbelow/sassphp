--TEST--
If there's an error while parsing, throw a SassException
--SKIPIF--
<?php if (!extension_loaded("sass")) print "skip"; ?>
--FILE--
<?php

try
{
    Sass::parse('askdgauwydv7iq2dq');
}
catch (SassException $e)
{
    echo 'Exception caught';
}

?>
--EXPECT--
Exception caught