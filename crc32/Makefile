.PHONY: env
env:
	virtualenv ../env
	../env/bin/python -m pip install -r ../requirements.txt
	echo "conda deactivate" >> ../env/bin/activate

build: lib
	cp __init__.py pkg/crc32/__init__.py
	cp libcrc32.so pkg/crc32/libcrc32.so
	../env/bin/python -m build pkg -o pkg

install: lib
	cp __init__.py pkg/crc32/__init__.py
	cp libcrc32.so pkg/crc32/libcrc32.so
	cp ../README.md pkg/README.md

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
	rm -Rf ../env
	rm -f *.o *.so *.out MANIFEST pkg/crc32/* pkg/README.md
	rm -Rf build dist
	rm -Rf pkg/dist
