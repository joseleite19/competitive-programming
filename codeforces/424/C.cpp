#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 1000006;

int n;
int cnt[N];

int main(){

    scanf("%d", &n);

    ll ans = 0;

    ll x;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &x);
        cnt[0] += n / i, cnt[i] -= n / i;
        cnt[1]++, cnt[(n % i) + 1]--;
        ans ^= x;
    }

    ll s = 0;
    for(int i = 0; i < n; i++){
        s += cnt[i];
        if(s & 1) ans ^= i;
    }

    printf("%lld\n", ans);


    return 0;
}
