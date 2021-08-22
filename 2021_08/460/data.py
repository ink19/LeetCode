#!/usr/bin/env  python3

print("LFUCache")
print("10000")

for i in range(10000):
    print("put")
    print("%d %d"%(i, i * 5))

for i in range(10000):
    print("get")
    print("%d"%i)