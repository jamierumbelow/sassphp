PHP_ARG_ENABLE(sass, [whether to enable sass extension],
[  --enable-sass      Enable sass extension], yes, yes)

if test "$PHP_SASS" != "no"; then

  LIBSASS_SEARCH_DIRS="./lib/libsass"
  
  for i in $LIBSASS_SEARCH_DIRS; do
      if test -f $i/sass_interface.h; then
          LIBSASS_DIR=$i
          LIBSASS_INCDIR=$i
      fi
  done

  if test -z "$LIBSASS_DIR"; then
      AC_MSG_ERROR(Cannot find libsass)
  fi

  PHP_ADD_INCLUDE($LIBSASS_INCDIR)
  PHP_ADD_LIBRARY_WITH_PATH(libsass, $LIBSASS_DIR, LIBSASS_SHARED_LIBADD)

  PHP_SUBST(SASS_SHARED_LIBADD)
  PHP_NEW_EXTENSION(sass, "src/sass.c", $ext_shared)
fi