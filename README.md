# sassphp

The `sass` extension for PHP gives you an object-oriented system of parsing [Sass](http://sass-lang.com/) from within your PHP applications. Under the hood it uses [libsass](https://github.com/hcatlin/libsass) to provide super speedy and compatible Sass parsing.

## Installation

Currently, the only way to install the extension is manually:

	$ git clone git://github.com/jamierumbelow/sassphp

Remember to grab your submodules:

	$ git submodule init
	$ git submodule update

...and compile!

	$ rake

The rake task will run the tests as well, so you'll have some output there.

Once compiled, you can install with `make`:

	$ make install

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