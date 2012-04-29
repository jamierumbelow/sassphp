PHP_ARG_ENABLE(sass, [whether to enable sass extension],
[  --enable-sass      Enable sass extension], yes, yes)

if test "$PHP_SASS" != "no"; then
  PHP_NEW_EXTENSION(sass, "src/sass.c", $ext_shared)
fi