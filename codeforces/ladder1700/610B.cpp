#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
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
const int N = 400005;

int n;
ll v[N];

int main(){

    scanf("%d", &n);

    forn(i, n) scanf("%lld", v+i);

    ll mn = v[0];
    forn(i, n) mn = min(mn, v[i]);

    forn(i, n) v[i+n] = v[i] -= mn;
    v[n+n] = 0;

    ll ans = n * mn;

    int tmp = 0, R;
    forn(i, n) if(v[i]){
        R = i;
        while(v[R]) R++;
        tmp = max(tmp, R - i);
        i = R-1;
    }

    ans += tmp;

    printf("%lld\n", ans);


    return 0;
}
