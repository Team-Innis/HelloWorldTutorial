#!/bin/sh
# AUTO-GENERATED FILE, DO NOT EDIT!
if [ -f $1.org ]; then
  sed -e 's!^C:/Users/tti12sjuhos/Programs/cygwin/lib!/usr/lib!ig;s! C:/Users/tti12sjuhos/Programs/cygwin/lib! /usr/lib!ig;s!^C:/Users/tti12sjuhos/Programs/cygwin/bin!/usr/bin!ig;s! C:/Users/tti12sjuhos/Programs/cygwin/bin! /usr/bin!ig;s!^C:/Users/tti12sjuhos/Programs/cygwin/!/!ig;s! C:/Users/tti12sjuhos/Programs/cygwin/! /!ig;s!^C:/users/kat11sJermuj/desktop/asdk!/build!ig;s! C:/users/kat11sJermuj/desktop/asdk! /build!ig;s!^Z:!/cygdrive/z!ig;s! Z:! /cygdrive/z!ig;s!^C:!/cygdrive/c!ig;s! C:! /cygdrive/c!ig;' $1.org > $1 && rm -f $1.org
fi
