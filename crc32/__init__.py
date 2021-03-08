from pkg_resources import resource_filename

_so_path = resource_filename(__name__, "libcrc32.so")
from functools import partial
import ctypes as _ctypes
import os.path as _path

__all__ = ['hash_func', "CRC32Table"]

crc32 = _ctypes.cdll.LoadLibrary(_so_path)

crc32.CRC32Update.restype = _ctypes.c_uint

_CRC32Table_length = 256
CRC32Table = (_ctypes.c_uint * _CRC32Table_length)(*[0 for _ in range(_CRC32Table_length)])

crc32.FillTable(CRC32Table)

import pdb; pdb.set_trace()

def hash_func(buffer):
    return crc32.CRC32Update(buffer, len(buffer), CRC32Table)
