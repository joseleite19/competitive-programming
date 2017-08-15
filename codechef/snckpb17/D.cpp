#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 100005;

vector<vector<int> > g;
vector<vector<int> > d;
int p[N];
int ans[N];

int f(int x){
    return p[x] == x ? x : p[x] = f(p[x]);
}

int n, m;
int main(){

    int t;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        scanf("%d %d", &n, &m);

        g.assign(n, vector<int>());
        d.assign(n, vector<int>());

        int u, v;
        for(int i = 0; i < m; i++){
            scanf("%d %d", &u, &v); u--, v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int i = 0; i < n; i++)
            d[ g[i].size() ].push_back(i);

        for(int i = 0; i < n; i++) p[i] = i;
        int cnt = n-1;

        for(int i = n-1; i >= 0; i--){
            ans[i] = cnt;
            for(int u : d[i]){
                for(int v : g[u]) if(g[v].size() >= i)
                    if(f(u) != f(v))
                        p[ f(u) ] = f(v), cnt--;
            }
        }

        printf("%d", ans[0]);
        for(int i = 1; i < n; i++)
            printf(" %d", ans[i]);
        printf("\n");
    }


    return 0;
}
