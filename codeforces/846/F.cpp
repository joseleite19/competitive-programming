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
const int N = 1000006;
int n, v[N], a[N], t[N];

int main(){

    scanf("%d", &n);

    forn(i, n) scanf("%d", v+i);

    forn(i, N) t[i] = -1;

    forn(i, n){
        a[i] = t[ v[i] ];
        t[ v[i] ] = i;
    }

    ll ans = 0;

    forn(i, n) ans += 1LL*(i - a[i]) * (n - i) - 1;

    printf("%.20lf\n", double(2*ans + n) / n / n);


    return 0;
}
