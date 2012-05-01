/**
 * Sass
 * PHP bindings to libsass - fast, native Sass parsing in PHP!
 * 
 * https://github.com/jamierumbelow/sassphp
 * Copyright (c)2012 Jamie Rumbelow <http://jamierumbelow.net>
 */

#ifndef PHP_SASS_H
#define PHP_SASS_H

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define SASS_VERSION "0.1.0"

#include <php.h>
#include <ext/standard/info.h>
#include <Zend/zend_extensions.h>
#include <Zend/zend_exceptions.h>

#include "lib/libsass/sass_interface.h"

zend_class_entry *sass_ce;
zend_class_entry *sass_exception_ce;

zend_class_entry *sass_get_exception_base();

PHP_METHOD(Sass, parse);
PHP_METHOD(Sass, parse_file);

#endif