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

ll dp[20][2][2000][2];
int mark[20][2][2000][2], pass;

ll dp2[20][2][2][2];
int mark2[20][2][2][2];

ll f(int i, int less, int last, int ja){
    if(i == sz) return last == n || ja;
    ll &ans = dp[i][less][last][ja];

    if(mark[i][less][last][ja] == pass) return ans;
    mark[i][less][last][ja] = pass;

    ans = 0;

    if(less){
        forn(d, 10){
            ans += f(i+1, 1, (last*10 + d) % k, ja | (last == n));
        }
    }
    else{
        forn(d, v[i]){
            ans += f(i+1, 1, (last*10 + d) % k, ja | (last == n));
        }
        ans += f(i+1, 0, (last*10 + v[i]) % k, ja | (last == n));
    }
    return ans;
}

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
            if(s) p |= (d == 0);
            ans += f2(i+1, 1, p, s || d);
        }
    }
    else{
        forn(d, v[i]){
            int p = ja;
            if(s) p |= (d == 0);
            ans += f2(i+1, 1, p, s || d);
        }
        int p = ja;
        if(s) p |= (v[i] == 0);
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

    if(t == 110){
        //printf("..%lld\n", f2(1, 0, 0, 1));
        //printf("..%lld\n", f2(1, 1, 0, 0));
        //printf("..%lld\n", f2(0, 0, 0, 0));
    }

    return 1+f2(0, 0, 0, 0);
}


ll solve(ll x){
    if(n == 0) return s2(x);

    if(x < 0) return 0;
    
    if(n >= 100) k = 1000;
    else if(n >= 10) k = 100;
    else k = 10;

    ll t = x;
    sz = 0;
    while(x) v[sz++] = x % 10, x /= 10;
    reverse(v, v+sz);
    pass++;

    return f(0, 0, 0, 0);
}

int main(){

    ll a, b;

    while(scanf("%lld %lld %d", &a, &b, &n) == 3 && a >= 0 && b >= 0)
        printf("%lld\n", solve(b) - solve(a-1));


    return 0;
}
