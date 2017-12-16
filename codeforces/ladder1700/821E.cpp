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
typedef vector<ll> vl;
typedef vector<vl> vll;

const ll oo = 1000000000000000000;
const int N = 100005;

vll operator*(const vll &a, const vll &b){
    vll c(a.size(), vl(b[0].size(), 0));
    
    forn(i, a.size()) forn(j, b[0].size())
        forn(k, b.size())
            c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;

    return move(c);
}

vll f(vll& b, ll e){
    vll ans(b.size(), vl(b.size(), 0));
    forn(i, ans.size()) ans[i][i] = 1;

    while(e){
        if(e & 1) ans = ans * b;
        b = b * b;
        e >>= 1;
    }
    return move(ans);
}


int main(){

    int n;
    ll k;

    scanf("%d %lld", &n, &k);

    ll a, b;
    int c;
    vll ans(16, vl(1, 0));
    ans[0][0] = 1;
    
    vll tmp(16, vl(16, 0));
    vl w(16, 0);
    while(n--){
        scanf("%lld %lld %d", &a, &b, &c);
        b = min(b, k);

        forn(i, 16) forn(j, 16) tmp[i][j] = 0;

        for1(i, c-1) tmp[i][i-1] = tmp[i][i] = tmp[i][i+1] = 1;
        
        if(c) tmp[0][0] = tmp[0][1] = tmp[c][c-1] = tmp[c][c] = 1;
        else tmp[0][0] = 1;

        ans = f(tmp, b - a) * ans;
    }

    printf("%lld\n", ans[0][0]);


    return 0;
}
