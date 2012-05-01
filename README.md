# sassphp

The `sass` extension for PHP gives you an object-oriented system of parsing [Sass](http://sass-lang.com/) from within your PHP applications. Under the hood it uses [libsass](https://github.com/hcatlin/libsass) to provide super speedy and compatible Sass parsing.

## What's Sass?

Sass is a CSS pre-processor language to add on exciting, new, awesome features to CSS. Sass was the first language of its kind and by far the most mature and up to date codebase.

Sass was originally created by Hampton Catlin ([@hcatlin](http://twitter.com/hcatlin)). The extension and continuing evolution of the language has all been the result of years of work by Nathan Weizenbaum ([@nex3](http://twitter.com/nex3)) and Chris Eppstein ([@chriseppstein](http://twitter.com/chriseppstein)).

For more information about Sass itself, please visit [http://sass-lang.com](http://sass-lang.com)

## Installation

Currently, the only way to install the extension is manually:

	$ git clone git://github.com/jamierumbelow/sassphp

Remember to grab your submodules:

	$ git submodule init
	$ git submodule update

...and compile it! I've written a little PHP script to do all the stuff you need to do:

	$ php install.php

Run the tests:

    $ make test

Finally, you can install with `make`:

	$ make install

And then add it to your _php.ini_:

    extension=sass.so

## Usage

This extension has a very simple API:

	$css = Sass::parse($source);

You can parse a file with `parse_file()`:

	$css = Sass::parse_file('path_to_file.scss');

If there's a problem, the extension will throw a `SassException`:

    try
    {
        $css = Sass::parse('dayrui3dui36di37');
    }
    catch (SassException $e)
    {
        // $e->getMessage() - ERROR -- , line 1: invalid top-level expression

        $css = FALSE;
    }