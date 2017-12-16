#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, r, l;

vector<int> g[2003];

int vis[2003], pass;

bool dfs(int u, int c){
    if(u == c) return true;
    vis[u] = pass;

    for(int v : g[u])
        if(vis[v] != pass)
            if(dfs(v, c))
                return true;

    return false;
}

int main(){

    scanf("%d %d %d", &n, &r, &l);

    map<int, vector<pair<int, int> > > xx, yy;
    for(int i = 0; i < l; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        xx[a].push_back(mp(b, i));
        yy[b].push_back(mp(a, i));
    }
    for(auto v : xx) sort(v.ss.begin(), v.ss.end());
    for(auto v : yy) sort(v.ss.begin(), v.ss.end());

    for(auto v : yy){
        for(auto u : v.ss){
            for(auto uu : v.ss){
                if(u == uu) continue;
                if(abs(uu.ff - u.ff) <= 2*r){ // -(!u & !uu) <=> (u | uu)
                    g[u.ss+l].push_back(uu.ss);
                    g[uu.ss+l].push_back(u.ss);
                }
            }
        }
    }

    for(auto v : xx){
        for(auto u : v.ss){
            for(auto uu : v.ss){
                if(u.ff == uu.ff) continue;
                if(abs(uu.ff - u.ff) <= 2*r){ // -(u & uu) <=> (!u | !uu)
                    g[u.ss].push_back(uu.ss+l);
                    g[uu.ss].push_back(u.ss+l);
                }
            }
        }
    }

    int ans = 1;
    for(int i = 0; i < l && ans; i++){
        pass++;
        if(!dfs(i, i+l)) continue;
        pass++;
        if(!dfs(i+l, i)) continue;
        ans = 0;
    }
    printf("%s\n", ans ? "YES" : "NO");
}
