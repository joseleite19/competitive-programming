#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long b, m;

inline long long gety(long long x){
    return b - (x + m-1) / m;
}

inline long long f(long long x, long long y){
    return (x+1)*y*(y+1)/2 + (y+1)*x*(x+1)/2;
}

int main(){

    scanf("%lld %lld", &m, &b);

    long long ans = 0;

    for(long long i = 0; i <= b*m; i++){
        ans = max(ans, f(i, gety(i)));
    }
    printf("%lld\n", ans);


    return 0;
}
