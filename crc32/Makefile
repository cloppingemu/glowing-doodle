env: clean
	echo "\nsetting up environment......\n\n"
	virtualenv ../env
	../env/bin/python -m pip install -r ../requirements.txt

build: lib env
	echo "\nsetting up python package......\n\n"
	cp __init__.py pkg/crc32/__init__.py
	cp libcrc32.so pkg/crc32/libcrc32.so
	../env/bin/python -m build pkg -o pkg -w

install: build
	echo "\ninstall python package......\n\n"
	../env/bin/python -m pip install pkg/crc*.whl

lib: clean
	echo "\ncompiling......\n\n"
	cc -c -Wall -Werror -fpic libcrc32.c -o libcrc32.o
	cc -shared -o libcrc32.so libcrc32.o

test: lib
	echo "\ntest......\n\n"
	# LD_LIBRARY_PATH=$(realpath .)
	cc -L . -Wall -o test.out tests/base.c -lcrc32

test-rpath: lib
	# export LD_LIBRARY_PATH=$(realpath .)
	cc -L . -Wall,-rpath=$(realpath .) -Wall -o test.out tests/base.c -lcrc32

clean:
	echo "\ncleaning......\n\n"
	rm -Rf ../env
	rm -f *.o *.so *.out MANIFEST pkg/crc32/* pkg/README.md pkg/crc32*.tar.gz pkg/crc32*.whl
	rm -Rf build dist
	rm -Rf pkg/dist pkg/build pkg/*.egg-info
