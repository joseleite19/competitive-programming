#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 500005;

int n;
ll v[N];

int main(){

    map<ll, int> cnt;

    scanf("%d", &n);

    forn(i, n) scanf("%lld", v+i);

    ll t = 0;

    forn(i, n-1) t += v[i], cnt[t]++; t += v[n-1];

    ll p = 0;
    ll ans = 0;

    if(t % 3) return printf("0\n"), 0;
    t /= 3;

    forn(i, n-2){
        p += v[i];
        cnt[p]--;
        if(p != t) continue;
        ans += cnt[2*p];
    }

    printf("%lld\n", ans);

    return 0;
}
