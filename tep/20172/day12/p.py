a = 18
b = 92
n = 1;
while b != 0:
	a, b = a * 18 - b * 92, a * 92 + 18 * b
	n = n + 1
	print(n)
