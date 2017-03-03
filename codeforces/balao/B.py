inp = file("derangements.in", "r")
q = file("derangements.out", "w")
r = inp.read()

dp = 300*[0]
fat = 300*[0]

dp[0] = 1
dp[1] = 0

fat[0] = 1;
fat[1] = 1;
n = int(r)

for x in xrange(2, 205):
	dp[x] = (x-1)*(dp[x-1] + dp[x-2])
	fat[x] = x*fat[x-1]


ans = 0
for x in xrange(1,n+1):
	ans += dp[x]*(2**x)*(fat[n] / (fat[x] * fat[n-x]))
	# print x
# print(dp[5])
# print(fat[6] / fat[2])

# for x in xrange(1,n+1):
# 	ans += dp[n]*(2**x)

# print(ans+1)
# print(dp[n]+1)
q.write(str(ans+1))
