import sys

N = 4004

f = N*[0]
for i in range(N):
    f[i] = N*[0]

f[0][0] = 1;

i = 0
while(True):
    s = "1"

    f[i][0] = 1
    f[i][i] = 1
    para = 0
    for j in range(1, i):
        f[i][j] = f[i-1][j] + f[i-1][j-1]
        if f[i][j] >= 10**60:
            para = 1
        s += " " + str(f[i][j])

    if i >= 1:
        s += " 1"
    i = i + 1
    print(s)
    if para:
        break
