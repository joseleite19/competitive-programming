dp = [0]*1000
for i in xrange(1,1000):
	dp[i] = [0]*1000

def C(n, k):
	if(n == k or k == 0 or n == 0):
		return 1

	if(dp[n][k]):
		return dp[n][k]
	dp[n][k] = C(n-1, k-1) + C(n-1, k)
	return dp[n][k]

ans = 0
inp = file("input.txt", "r")
q = file("output.txt", "w")
n = int(inp.read())
# n = input()

if n == 1:
	q.write('8')
else:
	tmp = n
	if tmp > 9:
		tmp = 9

	ans = 9*10**(n-1)
	for i in xrange(1, tmp+1):
		if i % 2:
			if i == n:
				ans = ans - 1
			else:
				ans -= 9*10**(n-i-1)*( C(tmp, i) - C(tmp-1, i-1)) + 10**(n-i)*C(tmp-1, i-1)
		else:
			if i == n:
				ans = ans + 1
			else:
				ans += 9*10**(n-i-1)*( C(tmp, i) - C(tmp-1, i-1)) + 10**(n-i)*C(tmp-1, i-1)
	q.write(str(ans))

