#include <bits/stdc++.h>

#define ss second
#define ff first
#define mp make_pair
#define pb push_back
#define eb emplace_back

using namespace std;

const int N = 5005;

vector<int> G[N];

int d[N], c[N], k[N], p[N];
int n, m, w;
int g, r, a;

void bfs(int s){
    memset(d, -1, sizeof d);

    d[s] = 0;

    queue<int> q;

    q.push(s);
    
    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : G[u]) if(d[v] == -1){
            d[v] = d[u]+1;
            q.push(v);
        }
    }
}

int f(){
    bfs(g);
    vector<pair<int, pair<int, int> > > v; // <time, <cost, qnt>>
    for(int i = 0; i < w; i++) if(d[ c[i] ] != -1)
        v.eb(d[ c[i] ], mp(p[i], k[i]));
    sort(v.begin(), v.end());
    long long cost = 0;
    int qnt = 0;
    multiset< pair<int, int> >s; //<cost, qnt>
    for(int i = 0; i < (int)v.size(); i++){
        if(qnt < r){
            int tmp = min(r - qnt, v[i].ss.ss);
            qnt += tmp;
            v[i].ss.ss -= tmp;
            cost += 1LL*tmp*v[i].ss.ff;
            s.insert(mp(v[i].ss.ff, tmp));
        }
        if(qnt == r){
            while(v[i].ss.ss){
                multiset<pair<int, int>>::iterator it = prev(s.end());
                if(it->ff <= v[i].ss.ff) break;
                int tmp = min(it->ss, v[i].ss.ss);
                cost -= 1LL*tmp*(it->ff);
                cost += 1LL*tmp*v[i].ss.ff;
                pair<int, int> np(it->ff, it->ss - tmp);
                s.erase(it);
                if(np.ss) s.insert(np);
                s.insert(mp(v[i].ss.ff, tmp));
                v[i].ss.ss -= tmp;
            }

            if(cost <= a) return v[i].ff;
        }
    }
    return -1;
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    scanf("%d", &w);

    for(int i = 0; i < w; i++)
        scanf("%d %d %d", c+i, k+i, p+i);

    int q;

    scanf("%d", &q);

    while(q--){
        scanf("%d %d %d", &g, &r, &a);
        printf("%d\n", f());
    }


	return 0;
}
