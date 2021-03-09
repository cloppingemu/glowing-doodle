.PHONY: env
env:
	virtualenv ../env
	../env/bin/python -m pip install -r ../requirements.txt

sdist: lib
	../env/bin/python setup.py sdist

build: lib
	../env/bin/python setup.py build_ext --inplace

install: lib
	../env/bin/python setup.py install

uninstall: clean
	../env/bin/python -m pip uninstall crc32


lib:
	cc -c -Wall -Werror -fpic libcrc32.c -o libcrc32.o
	cc -shared -o libcrc32.so libcrc32.o

test:
	# export LD_LIBRARY_PATH=$(realpath .)
	cc -L . -Wall -o test.out tests/base.c -lcrc32

test-rpath: lib
	# export LD_LIBRARY_PATH=$(realpath .)
	cc -L . -Wl,-rpath=$(realpath .) -Wall -o test.out tests/base.c -lcrc32

clean:
	rm -f *.o *.so *.out MANIFEST
	rm -Rf build dist

