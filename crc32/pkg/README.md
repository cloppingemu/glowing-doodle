# Glowing-Doodle

Mixed source Python module.

TODO:
- This project currently requires manually compiling C source. Find a way to natively or dynamically compile C if it is not already compiled.

- Fix module installation

Ensure cc is set to your preferred C compiler. _cd_ into crc32 and compile C source with _make lib_. In order to test the generated shared object, it has to be available in LD_LIBRARY_PATH (_export LD\_LIBRARY_PATH=$(realpath .)_). Then compile test with _make test_ and execute the test executable.


