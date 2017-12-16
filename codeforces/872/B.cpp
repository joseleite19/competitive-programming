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

int n, v[N], k, p[N], s[N];


int main(){

    scanf("%d %d", &n, &k);

    forn(i, n) scanf("%d", v+i);

    if(k >= 3){
        int ans = v[0];
        forn(i, n) ans = max(ans, v[i]);
        return printf("%d\n", ans), 0;
    }
    if(k == 1){
        int ans = v[0];
        forn(i, n) ans = min(ans, v[i]);
        return printf("%d\n", ans), 0;
    }

    p[0] = v[0];
    for1(i, n-1) p[i] = min(p[i-1], v[i]);
    s[n] = 1e9+1;

    ford(i, n) s[i] = min(s[i+1], v[i]);

    int ans = -1e9;

    forn(i, n-1){
        ans = max(ans, max(p[i], s[i+1]));
    }

    printf("%d\n", ans);

    return 0;
}
