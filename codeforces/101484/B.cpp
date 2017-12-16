#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

const int N = 1000006;

int x[N], y[N];

ll ans[N];
int xa[N], xb[N], ya[N], yb[N];

vector<pair<int, int> > points[N]; // <y, id>
vector<pair<int, pair<int, int> > > ev[N]; // <y1, <y2, add>>

ll ft[N];

ll query(int x){
    ll ans = 0;
    for(; x > 0; x -= x & -x)
        ans += ft[x];
    return ans;
}

ll sum(int x, ll v){
    for(; x < N; x += x & -x)
        ft[x] += v;
}

ll sum(int i, int j, ll v){
    sum(i, v);
    sum(j+1, -v);
}

int main(){

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d %d", x+i, y+i);

    for(int i = 0; i < m; i++){
        scanf("%d %d %d %d", xa+i, ya+i, xb+i, yb+i);
        xa[i]++, ya[i]++, yb[i]--;
    }

    {
        set<int> s;

        for(int i = 0; i < n; i++)
            s.insert(x[i]), s.insert(y[i]);
        for(int i = 0; i < m; i++)
            s.insert(xa[i]), s.insert(ya[i]), s.insert(xb[i]), s.insert(yb[i]);
        int p = 1;
        map<int, int> go;
        for(int x : s) go[x] = p++;

        s.clear();

        for(int i = 0; i < n; i++){
            x[i] = go[ x[i] ];
            y[i] = go[ y[i] ];
        }

        for(int i = 0; i < m; i++){
            xa[i] = go[ xa[i] ];
            ya[i] = go[ ya[i] ];
            xb[i] = go[ xb[i] ];
            yb[i] = go[ yb[i] ];
        }
        go.clear();
    }

    for(int i = 0; i < n; i++)
        points[ x[i] ].eb(y[i], i);

    for(int i = 0; i < m; i++){
        ev[ xa[i] ].eb(ya[i], mp(yb[i], 1));
        ev[ xb[i] ].eb(ya[i], mp(yb[i],-1));
    }

    for(int i = 1; i < N; i++){

        for(const auto &x : ev[i]){
            sum(x.ff, x.ss.ff, x.ss.ss);
        }

        for(const auto &x : points[i]){
            ans[x.ss] = query(x.ff);
        }

    }


    for(int i = 0; i < n; i++)
        printf("%lld\n", ans[i]);



    return 0;
}
