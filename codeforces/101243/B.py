inp = file("input.txt", "r")
q = file("output.txt", "w")
n = int(inp.read())

ans = 2**(2*n/3 - 1) + 2**(n/3 - 1) -1
if n % 2:
	ans += 2**(n/3 - 1) - 1;

q.write(str(ans))
