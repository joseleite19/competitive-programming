import fileinput


while True:
    try:
        line = str(input())
        m, j, t = line.split()
        j = int(j)//100
        t = int(t)
        m = int(m[0:-3]) + int(m[-2:])
        print(j)
        print(t)
        print(m)
        print(m * ((1 + j)**t))

    except(EOFError):
        j = 1
