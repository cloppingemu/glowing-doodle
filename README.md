# Glowing-Doodle

Mixed source Python module.

TODO:
- This project currently requires manually compiling C source. Find a way to natively or dynamically compile C if it is not already compiled.

In order to build and use the module, 

- Ensure cc is set to your preferred C compiler.

- _cd_ into crc32 and compile C source with _make lib_.

- Prepare the module for installation with _make build_. This will create a wheel file in the pgk folder. This file can installed with _python -m pip install \<filename\>.whl_.

- In order to test the generated shared object, it has to be available in LD_LIBRARY_PATH (_export LD\_LIBRARY\_PATH=$(realpath .)_). Then compile test with _make test_ and execute the test executable. Otherwise, _make test-rpath_ can be used to make test executable without LD_LIBRARY_PATH requirement -- location of the shared object is baked into the executable requiring the shared object to be available in the folder.


