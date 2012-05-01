/**
 * Sass
 * PHP bindings to libsass - fast, native Sass parsing in PHP!
 * 
 * https://github.com/jamierumbelow/sassphp
 * Copyright (c)2012 Jamie Rumbelow <http://jamierumbelow.net>
 */

#include <stdio.h>

#include "php_sass.h"
#include "utilities.h"

/* --------------------------------------------------------------
 * Sass
 * ------------------------------------------------------------ */

/**
 * $sass->parse(string $source, [  ]);
 *
 * Parse a string of Sass; a basic input -> output affair.
 */
PHP_METHOD(Sass, parse)
{
	// Define our source string and source string length
	char *source;
	int source_len;

	// Use zend_parse_parameters() to grab our source from the function call
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &source, &source_len) == FAILURE)
	{
		return;
	}

	// Create a new sass_context
	struct sass_context* context = sass_new_context();
	
	// We're not including anything and for the time being we only want to support
	// the nested style of output and not compressed.
	context->options.include_paths = "";
	context->options.output_style = SASS_STYLE_NESTED;

	// "Hand over the source, buddy!"
	// "Which one, béchamel or arrabbiata?"
	context->input_string = source;

	// Compile it!
	sass_compile(context);

	// Check the context for any errors...
	if (context->error_status)
	{
		zend_throw_exception(sass_exception_ce, trim(context->error_message), 0 TSRMLS_CC);
	}

	// Do we have an output?
	else if (context->output_string)
	{
		// Send it over to PHP.
		RETURN_STRING(context->output_string, 1);
	}

	// There's been a major issue
	else
	{
		// unknown internal error... throw an exception?
	}

	// Over and out.
	sass_free_context(context);
}

/**
 * $sass->parse_file(string $file_name);
 *
 * Parse a whole file FULL of Sass and return the CSS output
 */
PHP_METHOD(Sass, parse_file)
{
	// We need a file name and a length
	char *file;
	int file_len;

	// Grab the file name from the function
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &file, &file_len) == FAILURE)
	{
		return;
	}

	// First, do a little checking of our own. Does the file exist?
	if( access( file, F_OK ) == -1 )
	{
		char err[200];
		sprintf(err, "File %s could not be found", file);

		zend_throw_exception(sass_exception_ce, err, 0 TSRMLS_CC);
		return;
	}

	// Create a new sass_file_context
	struct sass_file_context* context = sass_new_file_context();
	
	// Default options
	context->options.include_paths = "";
	context->options.output_style = SASS_STYLE_NESTED;

	// File time
	context->input_path = file;

	// Compile it!
	sass_compile_file(context);

	// Check the context for any errors...
	if (context->error_status)
	{
		zend_throw_exception(sass_exception_ce, trim(context->error_message), 0 TSRMLS_CC);
	}

	// Do we have an output?
	else if (context->output_string)
	{
		// Send it over to PHP.
		RETURN_STRING(context->output_string, 1);
	}

	// There's been a major issue
	else
	{
		// unknown internal error... throw an exception?
	}

	// Over and out.
	sass_free_file_context(context);
}

/* --------------------------------------------------------------
 * EXCEPTION HANDLING
 * ------------------------------------------------------------ */

zend_class_entry *sass_get_exception_base()
{
    return zend_exception_get_default(TSRMLS_C);
}

/* --------------------------------------------------------------
 * PHP EXTENSION INFRASTRUCTURE
 * ------------------------------------------------------------ */

zend_function_entry sass_methods[] = {
    PHP_ME(Sass,  parse,     NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    PHP_ME(Sass,  parse_file,     NULL, ZEND_ACC_PUBLIC | ZEND_ACC_STATIC)
    {NULL, NULL, NULL}
};

static PHP_MINIT_FUNCTION(sass)
{
	zend_class_entry ce;
	zend_class_entry exception_ce;

	INIT_CLASS_ENTRY(ce, "Sass", sass_methods);
	sass_ce = zend_register_internal_class(&ce TSRMLS_CC);
	INIT_CLASS_ENTRY(exception_ce, "SassException", NULL);
    sass_exception_ce = zend_register_internal_class_ex(&exception_ce, sass_get_exception_base(), NULL TSRMLS_CC);

	#define REGISTER_SASS_CLASS_CONST_LONG(name, value) zend_declare_class_constant_long(sass_ce, ZEND_STRS( #name ) - 1, value TSRMLS_CC)

    REGISTER_SASS_CLASS_CONST_LONG("STYLE_NESTED", SASS_STYLE_NESTED);
    REGISTER_SASS_CLASS_CONST_LONG("STYLE_EXPANDED", SASS_STYLE_EXPANDED);
    REGISTER_SASS_CLASS_CONST_LONG("STYLE_COMPACT", SASS_STYLE_COMPACT);
    REGISTER_SASS_CLASS_CONST_LONG("STYLE_COMPRESSED", SASS_STYLE_COMPRESSED);

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(sass)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "version", SASS_VERSION);
	php_info_print_table_end();
}

static zend_module_entry sass_module_entry = {
	STANDARD_MODULE_HEADER,
	"sass",
	NULL,
	PHP_MINIT(sass),
	NULL,
	NULL,
	NULL,
	PHP_MINFO(sass),
	SASS_VERSION,
	STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_SASS
ZEND_GET_MODULE(sass)
#endif