sdist: lib
	../env/bin/python setup.py sdist

build:
	../env/bin/python setup.py build_ext --inplace

install:
	../env/bin/python setup.py install

uninstall: clean
	../env/bin/python -m pip uninstall crc32


lib:
	gcc -c -Wall -Werror -fpic libcrc32.c -o libcrc32.o
	gcc -shared -o libcrc32.so libcrc32.o

test: lib
	# export LD_LIBRARY_PATH=$(realpath .)
	gcc -L tests/ -Wall -o test.out tests/base.c -lcrc32

test-rpath: lib
	# export LD_LIBRARY_PATH=$(realpath .)
	gcc -L tests/ -Wl,-rpath=$(realpath .) -Wall -o test.out tests/base.c -lcrc32

clean:
	rm -f *.o *.so *.out
	rm -Rf build dist

