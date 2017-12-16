
N = 1500

fib = [0 for _ in range(N)]
fib[0] = 0
fib[1] = 1
for i in range(2, N-1):
    fib[i] = fib[i-1] + fib[i-2]

p = [0 for _ in range(N)] 
for i in range(1, N-1):
    p[i] = p[i-1] + fib[i]

t = int(input())
for tc in range(t):
    n = int(input())
    n = n + 2
    if n < 1:
        print(0)
    else:
        print(p[n] - n)
