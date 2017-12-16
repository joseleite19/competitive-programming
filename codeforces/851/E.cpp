#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 1000006;

ll v[N];

map<int, int> dp;

int mex(const set<int> &s){
    int ans = 0;
    while(s.count(ans)) ans++;
    return ans;
} 

int g(int bit){
    if(dp.count(bit)) return dp[bit];

    int lg = 31 - __builtin_clz(bit);
    set<int> s;
    for(int i = 0; i <= lg; i++){
        int q = 0;
        for(int j = 0; j <= lg; j++) if(bit & (1 << j)){
            if(j < i) q |= 1 << j;
            if(j > i) q |= 1 << (j - i-1);
        }
        s.insert(g(q));
    }
    return dp[bit] = mex(s);
}

int main(){

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    map<int, int> m;

    for(int i = 0; i < n; i++){
        ll x = v[i];
        for(ll j = 2; j*j <= x; j++){
            if(x % j == 0){
                int tmp = 0;
                while(x % j == 0) tmp++, x /= j;
                m[j] |= 1 << (tmp-1);
            }
        }
        if(x > 1) m[x] |= 1;
    }

    dp[0] = 0;

    int ans = 0;
    for(auto x : m)
        ans ^= g(x.ss);

    printf("%s\n", ans ? "Mojtaba" : "Arpa");


    return 0;
}
