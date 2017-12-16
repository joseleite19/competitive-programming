#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int pX[6002], pY[6002], distX[6002], distY[6002], pass, source = 6000, target = 6001, n, q, x, y, b, e;

vector<int> g[6002];

bool bfs(){
    bool found = false;
    queue<int> Q;

    for(int i = 0; i < q; i++) if(pX[i] == -1)
        Q.push(i);

    memset(distX, 0, sizeof distX);
    memset(distY, 0, sizeof distY);

    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(int i = 0; i < (int)g[u].size(); i++){
            int v = g[u][i];
            if(distY[v] == 0){
                distY[v] = distX[u]+1;
                if(pY[v] == -1) found = true;
                else distX[pY[v]] = distY[v]+1, Q.push(pY[v]);
            }
        }
    }
    return found;
}

bool dfs(int u){
    for(int i = 0; i < (int)g[u].size(); i++){
        int v = g[u][i];
        if(distY[v] == distX[u]+1){
            distY[v] = 0;
            if(pY[v] == -1 || dfs(pY[v])){
                pX[u] = v, pY[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main(){

    scanf("%d %d", &n, &q);
    vector<pair<int, pair<int, pair<int,int> > > > pontos(q);

    for(int i = 0; i < q; i++){
        scanf("%d %d %d %d", &x, &y, &b, &e);
        pontos[i] = mp(x, mp(y, mp(b, e)));
    }

    sort(pontos.begin(), pontos.end(), [] (const pair<int, pair<int, pair<int,int> > > &lhs, const pair<int, pair<int, pair<int,int> > > &rhs) {
        int xf = lhs.ss.ss.ff, xs = lhs.ss.ss.ss;
        int sf = rhs.ss.ss.ff, ss = rhs.ss.ss.ss;

        return xf < sf || (xf == sf && xs < ss);
    });

    for(int i = 0; i < q; i++){
        for(int j = i+1; j < q; j++){
            long long xx = (pontos[i].ff - pontos[j].ff);
            long long yy = (pontos[i].ss.ff - pontos[j].ss.ff);
            double dist = sqrt(xx*xx + yy*yy);
            if(pontos[i].ss.ss.ss + dist + 1e-6 <= pontos[j].ss.ss.ff){
                g[i].push_back(3000+j);
                g[3000+j].push_back(i);
            }
        }
    }

    int ans = 0;
    memset(pX, -1, sizeof pX);
    memset(pY, -1, sizeof pY);

    while(bfs())
        for(int i = 0; i < q; i++)
            if(pX[i] == -1 && dfs(i))
                ans++;

    ans;

    printf("%c\n", q - ans <= n ? 'S' : 'N');
    return 0;
}