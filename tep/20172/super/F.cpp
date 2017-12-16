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

int k, n;
int sz, v[100];

int pass;

ll dp2[20][2][20][2];
int mark2[20][2][20][2];

ll t;
ll f2(int i, int less, int ja, int s){
    if(i == sz) return ja;
    ll &ans = dp2[i][less][ja][s];

    if(mark2[i][less][ja][s] == pass) return ans;
    mark2[i][less][ja][s] = pass;

    ans = 0;

    if(less){
        forn(d, 10){
            int p = ja;
            if(s) p += (d == 0);
            ans += f2(i+1, 1, p, s || d);
        }
    }
    else{
        forn(d, v[i]){
            int p = ja;
            if(s) p += (d == 0);
            ans += f2(i+1, 1, p, s || d);
        }
        int p = ja;
        if(s) p += (v[i] == 0);
        ans += f2(i+1, 0, p, s || v[i]);
    }

    return ans;
}


ll s2(ll x){
    if(x < 0) return 0;
    t = x;
    sz = 0;
    while(x) v[sz++] = x % 10, x /= 10;
    reverse(v, v+sz);
    pass++;
    pass++;

    return 1+f2(0, 0, 0, 0);
}


int main(){

    ll a, b;

    while(scanf("%lld %lld", &a, &b) == 2 && a >= 0 && b >= 0)
        printf("%lld\n", s2(b) - s2(a-1));


    return 0;
}
