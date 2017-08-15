#include <bits/stdc++.h>

using namespace std;


int main(){

    long long n, k;

    scanf("%lld %lld", &n, &k);

    long long limit = n/2;

    long long tmp = limit % (k+1);

    long long a, b, c;

    a = limit, b = 0, c = 0;

    c = n - limit + tmp;

    limit -= tmp;

    a = limit / (k+1);

    b = limit - a;

    printf("%lld %lld %lld\n", a, b, c);


    return 0;
}
