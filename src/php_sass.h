#ifndef PHP_SASS_H
#define PHP_SASS_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define SASS_VERSION "0.1.0"

#include <php.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>

#include "lib/libsass/sass_interface.h"

zend_class_entry *sass_ce;

PHP_METHOD(Sass, __construct);
PHP_METHOD(Sass, parse);
PHP_METHOD(Sass, parse_file);
PHP_METHOD(Sass, parse_directory);

#endif