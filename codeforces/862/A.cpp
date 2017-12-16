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
#define fore(i, n) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int n;
int v[N];

int main(){

    int x;
    scanf("%d %d", &n, &x);

    forn(i, n){
        int q;
        scanf("%d", &q);
        v[q] = 1;
    }

    int ans = 0;
    forn(i, x) ans += !v[i];

    if(v[x]) ans++;

    printf("%d\n", ans);

    return 0;
}
