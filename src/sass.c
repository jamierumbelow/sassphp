#include "php_sass.h"

PHP_METHOD(Sass, __construct) { }

PHP_METHOD(Sass, parse)
{
	char *source;
	int source_len;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &source, &source_len) == FAILURE)
	{
		return;
	}

	struct sass_context* context = sass_new_context();
	
	context->options.include_paths = "";
	context->options.output_style = SASS_STYLE_NESTED;

	context->input_string = source;

	sass_compile(context);

	if (context->error_status)
	{
		// throw error
	}
	else if (context->output_string)
	{
		RETURN_STRING(context->output_string, 0);
	}

	sass_free_context(context);
}

PHP_METHOD(Sass, parse_file)
{

}

PHP_METHOD(Sass, parse_directory)
{

}

zend_function_entry sass_methods[] = {
    PHP_ME(Sass,  __construct,     NULL, ZEND_ACC_PUBLIC | ZEND_ACC_CTOR)
    PHP_ME(Sass,  parse,     NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Sass,  parse_file,     NULL, ZEND_ACC_PUBLIC)
    PHP_ME(Sass,  parse_directory,     NULL, ZEND_ACC_PUBLIC)
    {NULL, NULL, NULL}
};

static PHP_MINIT_FUNCTION(sass)
{
	zend_class_entry ce;

	INIT_CLASS_ENTRY(ce, "Sass", sass_methods);
	sass_ce = zend_register_internal_class(&ce TSRMLS_CC);

	return SUCCESS;
}

static PHP_MINFO_FUNCTION(sass)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "Version", SASS_VERSION);
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