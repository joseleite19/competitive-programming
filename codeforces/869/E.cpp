#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000000000000009
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

ll add(ll a, ll b){
    ll ans = a + b;
    while(ans >= MOD) ans -= MOD;
    while(ans < 0) ans += MOD;
    return ans;
}

class bit2d{
    int n, m;
    vector<vector<ll> > ft;

public:
    bit2d(int a = 0, int b = 0) : n(a), m(b), ft(a+1, vector<ll>(b+1, 0)){}
    void update(int x, int y, ll v){
        if(x == 0 || y == 0) return;
        for(; x <= n; x += x & -x)
            for(int y0 = y; y0 <= m; y0 += y0 & -y0)
                ft[x][y0] = add(ft[x][y0], v);
    }

    ll query(int x, int y){
        ll ans = 0;
        for(; x > 0; x -= x & -x)
            for(int yy = y; yy > 0; yy -= yy & -yy)
                ans = add(ans, ft[x][yy]);
        return ans;
    }
    void update(int a, int b, int c, int d, ll v){
        update(a, b, v);
        update(c+1, b, -v);
        update(a, d+1, -v);
        update(c+1, d+1, v);
    }

    ll query(int a, int b, int c, int d){
        return query(c, d) - query(c, b-1) - query(a-1, d) + query(a-1, b-1);
    }

};

ll mul(ll a, ll b){
    ll ans = 0;
    while(b){
        if(b & 1) ans = (ans + a) % MOD;
        a = (a + a) % MOD;
        b /= 2;
    }
    return ans;
}

ll val(int x){
    ll ans = 1;
    ll b = 2;
    while(x){
        if(x & 1) ans = mul(ans, b);
        b = mul(b, b);
        x /= 2;
    }
    return ans;
}

int main(){

    int n, m, q;

    scanf("%d %d %d", &n, &m, &q);

    bit2d ft(n, m);

    int t, r1, c1, r2, c2;

    set<int> av;

    forn(i, N) av.insert(i);
    map<tuple<int, int, int, int>, int> go;

    vector<int> w;

    while(q--){

        scanf("%d %d %d %d %d", &t, &r1, &c1, &r2, &c2);

        if(t == 1){
            int x = *av.begin(); av.erase(x);
            go[mt(r1, c1, r2, c2)] = x;
            ft.update(r1, c1, r2, c2, val(x));
        }
        else if(t == 2){
            int x = go[mt(r1, c1, r2, c2)];
            go.erase(mt(r1, c1, r2, c2));
            ft.update(r1, c1, r2, c2, -val(x));
            av.insert(x);
        }
        else{
            printf("%s\n", ft.query(r1, c1) == ft.query(r2, c2) ? "Yes" : "No");
        }
    
    }


    return 0;
}
