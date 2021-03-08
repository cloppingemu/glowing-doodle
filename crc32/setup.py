# from distutils.core import setup, Extension
import distutils.core

def main():
    distutils.core.setup(
        name="crc32",
        version="1.0.0",
        ext_modules=[distutils.core.Extension("crc32", ["libcrc32.c"]), ]
    )

if __name__ == "__main__":
    main()

