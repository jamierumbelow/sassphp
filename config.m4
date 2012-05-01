PHP_ARG_ENABLE(sass, [whether to enable sass extension],
[  --enable-sass      Enable sass extension], yes, yes)

if test "$PHP_SASS" != "no"; then
  PHP_ADD_LIBRARY_WITH_PATH(sass, lib/libexec, LIBSASS_SHARED_LIBADD)

  LDFLAGS="-lsass -L/Users/jamierumbelow/Sites/sassphp/lib/libsass/"

  PHP_NEW_EXTENSION(sass, src/sass.c src/utilities.c, $ext_shared)
fi