gcc -c cmath.c -msse2
ar rcs libcmath.lib cmath.o

gcc -c fenwick.c
ar rcs libfenwick.lib fenwick.o