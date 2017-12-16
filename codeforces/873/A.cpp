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

int n, v[N];

int main(){

    int k, x;
    scanf("%d %d %d", &n, &k, &x);

    forn(i, n) scanf("%d", v+i);

    sort(v, v+n); reverse(v, v+n);

    ll ans = 0;

    forn(i, n){
        if(k) k--, ans += x;
        else ans += v[i];
    }

    printf("%lld\n", ans);



    return 0;
}
