#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007
#define oo 1000000000000000000

using namespace std;

int n;
long long v[200005];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    if(n == 2) return printf("%lld\n", abs(v[0] - v[1])), 0;

    long long sum = 0;
    for(int i = 1; i < n; i++)
        sum += v[i];

    long long tmp = v[0];
    long long ans = oo;
    for(int i = 1; i < n; i++){
        ans = min(ans, abs(tmp - sum));
        tmp += v[i];
        sum -= v[i];
    }

    printf("%lld\n", ans);



    return 0;
}
