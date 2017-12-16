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

int k;
int sz, v[100];

ll dp[20][2][100][100];
int mark[20][2][100][100], pass;

ll f(int i, int less, int rs, int rt){
    if(i == sz) return rs == 0 && rt == 0;
    ll &ans = dp[i][less][rs][rt];

    if(mark[i][less][rs][rt] == pass) return ans;
    mark[i][less][rs][rt] = pass;

    ans = 0;

    if(less){
        forn(d, 10){
            ans += f(i+1, 1, (rs + d) % k, (rt * 10 + d) % k);
        }
    }
    else{
        forn(d, v[i]){
            ans += f(i+1, 1, (rs + d) % k, (rt * 10 + d) % k);
        }
        ans += f(i+1, 0, (rs + v[i]) % k, (rt * 10 + v[i]) % k);
    }
    return ans;
}

ll solve(int n){
    if(k > 95) return 0;
    sz = 0;
    while(n) v[sz++] = n % 10, n /= 10;
    reverse(v, v+sz);
    pass++;
    return f(0, 0, 0, 0);
}

int main(){

    int t;

    scanf("%d", &t);

    for1(tc, t){
        int a, b;
        scanf("%d %d %d", &a, &b, &k);
        printf("%lld\n", solve(b) - solve(a-1));
    }


    return 0;
}
