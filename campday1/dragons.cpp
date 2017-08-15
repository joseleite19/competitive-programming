#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

#define oo 1000000000000000007

using namespace std;

const int N = 3000;

vector<int> g[N];

int vis[N];

int p[N];

int f(int x){ return x == p[x] ? x : p[x] = f(p[x]); }

vector<pair<int, int>> v[N];

int main(){

    int n, F, d;

    scanf("%d %d %d", &n, &F, &d);

    for(int i = 0; i < n; i++) p[i] = i;

    for(int i = 0; i < F; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
        if(f(a) != f(b)) p[f(a)] = f(b);
    }

    for(int i = 0; i < d; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        int x = f(a);
        v[x].eb(c, b);
    }

    for(int i = 0; i < n; i++) sort(v[i].begin(), v[i].end());

    long long ans = 0;

    for(int i = 0; i < n; i++) if(!vis[f(i)]){
        int p = f(i);
        vis[p] = 1;
        if(v[p].empty()) continue;
        long long tmp = oo, sum = 0;
        for(int j = v[p].size()-1; j >= 0; j--){
            pair<int, int> q = v[p][j];
            tmp = min(tmp, max(sum, q.ff+1LL));
            sum += q.ss;
        }
        tmp = min(tmp, sum);
        ans += tmp;
    }

    printf("%lld\n", ans);


}
