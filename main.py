import time
import crc32

def create_table():
    a = []
    for i in range(256):
        k = i
        for j in range(8):
            if k & 1:
                k ^= 0x1db710640
            k >>= 1
        a.append(k)
    return a
 
def crc_update(buf, crc, table):
    crc ^= 0xffffffff
    for k in buf:
        crc = (crc >> 8) ^ table[(crc & 0xff) ^ k]
    return crc ^ 0xffffffff
 
crc_table = create_table()
s = "The quick brown fox jumps over the lazy dog"
rep = 100000
t0 = time.time()
for _ in range(rep):
    crc_update(s.encode(), 0, crc_table)
t1 = time.time()
for _ in range(rep):
    crc32.hash(s)
t2 = time.time()

print({"python": t1-t0, "C":t2-t1})
# {'python': 1.000, 'C': 0.105} seconds
