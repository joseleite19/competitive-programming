import sys

f = 1001*[0]
f[1] = 1
f[0] = 1

for i in range(2, 1001):
    for l in range(0, i):
        f[i] += f[l]*f[i-l-1]

for line in sys.stdin:
    print(f[int(line)])

