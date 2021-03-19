# from pkg_resources import resource_filename
# _so_path = resource_filename(__name__, "libcrc32.so")

import pkgutil
_so_path = "/".join((pkgutil.extend_path(__path__, __name__)[0], "libcrc32.so"))

__author__ = "Clopping Emu"
__version__ = "0.1"

from functools import partial
import ctypes as _ctypes
import os.path as _path

__all__ = ['hash_func', "table"]

clibcrc32 = _ctypes.cdll.LoadLibrary(_so_path)

clibcrc32.CRC32Update.restype = _ctypes.c_uint

_table_size = 256
table = (_ctypes.c_uint * _table_size)(*[0 for _ in range(_table_size)])
clibcrc32.FillTable(table)

def hash(buffer):
    return clibcrc32.CRC32Update(buffer.encode(), len(buffer), table)
