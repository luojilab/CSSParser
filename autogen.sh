if test -z "$LIBTOOLIZE" -a "`uname`" = "Darwin"; then
  if command -v "glibtoolize" >/dev/null; then
    LIBTOOLIZE=glibtoolize
  elif command -v "libtoolize" >/dev/null; then
    LIBTOOLIZE=libtoolize
  else
    echo "autogen.sh: line $LINENO: command glibtoolize or libtoolize not found"
    exit 1
  fi
fi

autoreconf --install
