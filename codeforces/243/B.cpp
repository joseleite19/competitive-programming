#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
int n, m, h, t;

int vis[N];
vector<int> g[N];

int ansu = -1, ansv = -1;

bool check(int u, int v){
    if(ansu != -1) return false;
    if(g[u].size() < h+1) return false;
    if(g[v].size() < t+1) return false;

    if(g[u].size() > h+t+1 || g[v].size() > h+t+1){
        ansu = u, ansv = v;
        return true;
    }

    for(int t : g[u]) if(t != v)
        vis[t] = 1;
    
    int cnt = 0;
    for(int t : g[v]) if(t != u)
        if(vis[t])
            cnt++;

    for(int t : g[u]) vis[t] = 0;

    if(int(g[u].size())-1 + int(g[v].size())-1 - cnt >= h+t){
        ansu = u, ansv = v;
        return true;
    }

    return false;
}

void f(set<int>& s, int u, int v, int sz, const set<int> &o){
    
    for(int t : g[v]) if(t != u)
        vis[t] = 1;
    for(int t : g[u]) if(t != v && !vis[t] && s.size() < sz)
        s.insert(t);
    for(int t : g[u]) if(t != v && vis[t] && !o.count(t) && s.size() < sz)
        s.insert(t);
}

int main(){

    scanf("%d %d %d %d", &n, &m, &h, &t);

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int u = 1; u <= n && ansu == -1; u++)
        for(int v : g[u])
            if(check(u, v))
                break;

    if(ansu == -1) return printf("NO\n"), 0;

    printf("YES\n");

    set<int> ans1, ans2;

    f(ans1, ansu, ansv, h, ans2);
    f(ans2, ansv, ansu, t, ans1);

    printf("%d %d\n", ansu, ansv);

    for(int t : ans1) printf(" %d", t);
    printf("\n");

    for(int t : ans2) printf(" %d", t);
    printf("\n");


    return 0;
}
