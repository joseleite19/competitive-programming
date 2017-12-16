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
const int N = 100005;

int n, m, a[N], b[N];

int main(){

    scanf("%d %d", &n, &m);

    forn(i, n) scanf("%d", a+i);
    forn(i, m) scanf("%d", b+i);

    set<int> s;

    forn(i, n) s.insert(a[i]);

    ll ans = oo;

    forn(i, m) if(s.count(b[i]))
        ans = min(ans, 1LL*b[i]);

    forn(i, n) forn(j, m)
        ans = min(ans, 10LL*a[i] + b[j]),
        ans = min(ans, 10LL*b[j] + a[i]);

    printf("%lld\n", ans);



    return 0;
}
