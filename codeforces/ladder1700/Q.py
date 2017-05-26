a, b=input().split()
a, b=[int(a), int(b)]

import math

def mdc(a, b):
    if 1<=a<=1000 and 1<=b<=1000:
        print(math.gcd(a, b))
    else:
        None
mdc(a, b)