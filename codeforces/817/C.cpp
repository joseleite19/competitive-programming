#include <bits/stdc++.h>

using namespace std;

long long n, s;
vector<int> d;

bool f(long long x){
    long long val = x;
    long long sum = 0;
    while(val) sum += val % 10, val /= 10;
    return x - sum >= s;
}

int main(){

    scanf("%lld %lld", &n, &s);

    long long ans = s;
    while(ans <= n + 1 && !f(ans)) ans++;

    printf("%lld\n", max(0LL, n - ans + 1));

    return 0;
}
