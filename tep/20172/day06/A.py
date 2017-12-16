import sys

N = 4004

f = N*[0]
for i in range(N):
    f[i] = N*[0]



for i in range(2, N):
    f[i] = f[i-1] + f[i-2]

for line in sys.stdin:
    if int(line) == 0:
        break
    print(f[2*int(line)])

