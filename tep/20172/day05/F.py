import sys

f = 500*[1]

for i in range(2, 300):
    f[i] = f[i-1] + 2*f[i-2]

for line in sys.stdin:
    print(f[int(line)])

