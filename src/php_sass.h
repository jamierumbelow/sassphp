#ifndef PHP_SASS_H
#define PHP_SASS_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define SASS_VERSION "0.1.0"

#include <php.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>

int sass_setup(TSRMLS_D);

PHP_FUNCTION(sass_test);

#endif