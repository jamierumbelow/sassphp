#include "php_sass.h"

static PHP_MINIT_FUNCTION(sass)
{
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(sass)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "Version", SASS_VERSION);
	php_info_print_table_end();
}

static zend_function_entry sass_functions[] = {
	PHP_FE(sass_test, NULL)
	{ NULL, NULL, NULL }
};

static zend_module_entry sass_module_entry = {
	STANDARD_MODULE_HEADER,
	"sass",
	sass_functions,
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

PHP_FUNCTION(sass_test)
{
    RETURN_STRING("Hello World", 1);
}