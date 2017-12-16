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
const int N = 1000006;

vector<pair<int, int>> d[N];
int v[N];
int vis[N];
set<int> tmp[N];

int main(){
    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    for(int i = 0; i < n; i++)
        for(int j = i+1; j < n; j++){
            int c = abs(v[i] - v[j]);
            if(!tmp[c].count(i) || !tmp[c].count(j)){
                d[c].eb(i, j);
                tmp[c].insert(i), tmp[c].insert(j);
            }
        }

    int ans = 1;

    for(ans = 1; ans < N; ans++){
        int cnt = 0;
        for(int j = ans; j < N; j += ans){
            //cnt += d[j];
            for(auto x : d[j]){
                if(vis[x.ff] == ans && vis[x.ss] == ans) continue;
                vis[x.ff] = vis[x.ss] = ans;
                cnt++;
                if(cnt > k) break;
            }
        }
        if(cnt <= k) break;
    }

    printf("%d\n", ans);

    return 0;
}
