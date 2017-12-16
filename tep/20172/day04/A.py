import fileinput
for line in fileinput.input():
    line = line.strip()
    print(line)
    a = int(line.split()[0])
    b = int(line.split()[2])
    
    if a >= 2**31:
        print("first number too big")
    if b >= 2**31:
        print("first number too big")

    if eval(line) >= 2**31:
        print("result too big")
