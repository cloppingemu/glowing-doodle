.PHONY: env
env: clean
	virtualenv ../env
	../env/bin/python -m pip install -r ../requirements.txt

build: lib env
	cp __init__.py pkg/crc32/__init__.py
	cp libcrc32.so pkg/crc32/libcrc32.so
	../env/bin/python -m build pkg -o pkg

lib: clean
	cc -c -Wall -Werror -fpic libcrc32.c -o libcrc32.o
	cc -shared -o libcrc32.so libcrc32.o

test: lib
	# export LD_LIBRARY_PATH=$(realpath .)
	cc -L . -Wall -o test.out tests/base.c -lcrc32

test-rpath: lib
	# export LD_LIBRARY_PATH=$(realpath .)
	cc -L . -Wl,-rpath=$(realpath .) -Wall -o test.out tests/base.c -lcrc32

clean:
	rm -Rf ../env
	rm -f *.o *.so *.out MANIFEST pkg/crc32/* pkg/README.md pkg/*.tar.gz pkg/*.whl
	rm -Rf build dist
	rm -Rf pkg/dist pkg/build pkg/*.egg-info
