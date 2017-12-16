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
const int N = 4000006;

int a[N], b[N];
int n;

int vis[N];

int main(){

    scanf("%d", &n);

    forn(i, n) scanf("%d", a+i), vis[ a[i] ] = 1;
    forn(i, n) scanf("%d", b+i), vis[ b[i] ] = 1;

    int ans = 0;

    forn(i, n)
        forn(j, n)
            ans += vis[ a[i] ^ b[j] ];

    printf("%s\n", ans & 1 ? "Koyomi" : "Karen");


    return 0;
}
