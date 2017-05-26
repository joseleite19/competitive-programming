import random
from math import sqrt
from math import pi
from fractions import gcd

def r():
	# return random.getrandbits(32768)
	# return random.getrandbits(1024)
	return random.getrandbits(128)

cnt = 0
limit = 100000
for x in range(1, limit):
	if gcd(r(), r()) == 1:
		cnt = cnt + 1
ans = sqrt(limit*6.0/cnt)
print ans, 'error of', 100*abs(ans - pi) / pi, "%"
