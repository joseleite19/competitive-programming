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
const int N = 100005;

ll pot(ll b, ll e){
    ll ans = 1;
    while(e--) ans *= b;
    return ans;
}

ll d(const vector<ll>& v, ll x){
    ll ans = 0;
    for(int i = 1; i < v.size(); i++)
        ans += v[i] * i * pot(x, i-1);
    return ans;
}

ll f(const vector<ll> &v, ll x){
    ll ans = 0;
    for(int i = 0; i < v.size(); i++)
        ans += v[i] * pot(x, i);
    return ans;
}

ll root(vector<ll> v){
    ll x = 12;
    for(int it = 0; it < 20; it++) if(d(v, x))
        x = x - f(v, x) / d(v, x);
    for(ll q = x - 100; q < x + 100; q++)
        if(f(v, q) == 0)
            return q;
    return oo;
}

bool eval(vector<ll> v){
    if(v.size() == 2) return 0;

    ll x = root(v);
    if(x == oo) return 1;

    // check if exists a 2 degree polynomial that divides v
}

int main(){

    int t;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        int n;

        scanf("%d", &n);

        int x;
        vector<ll> v;
        v.pb(1);
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            v.pb(x);
        }
        reverse(v.begin(), v.end());
        printf("Caso %d: %s\n", tc, eval(v) ? "Sim" : "Nao");
    }


    return 0;
}
