#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 100005;

vector<int> g[N];
int n;
int out[N];

int main(){

    int m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        out[u]++;
        g[v].push_back(u);
    }

    priority_queue<int> pq;
    for(int i = 1; i <= n; i++) if(!out[i])
        pq.push(i);

    vector<int> ans;

    while(!pq.empty()){
        int u = pq.top(); pq.pop();
        ans.push_back(u);
        for(int v : g[u]){
            out[v]--;
            if(!out[v]){
                pq.push(v);
            }
        }
    }

    reverse(ans.begin(), ans.end());

    vector<int> pos(n+1);

    for(int i = 0; i < ans.size(); i++)
        pos[ ans[i] ] = i+1;

    for(int i = 1; i <= n; i++)
        printf("%d ", pos[i]);
    printf("\n");

    return 0;
}
