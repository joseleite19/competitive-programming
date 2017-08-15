#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define oo 2000000001
#define mp make_pair

using namespace std;

const int N = 200005;

int n, x;

vector<pair<int, int> > l[N], r[N];

int best[2*N];

int main(){

    scanf("%d %d", &n, &x);

    for(int i = 0; i < n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        l[a].push_back(mp(b, c));
        r[b].push_back(mp(a, c));
    }

    for(int i = 0; i < N; i++) best[i] = oo;

    int ans = oo;
    for(int i = 0; i < N; i++){
        //process l
        for(pair<int, int> p : l[i]){
            int id = x - (p.ff - i + 1);
            if(id < 0) continue;
            if(best[id] == oo) continue;
            ans = min(ans, p.ss + best[id]);
        }


        //process r
        for(pair<int, int> p : r[i]){
            int id = i - p.ff + 1;
            best[id] = min(best[id], p.ss);
        }
    }

    if(ans == oo) ans = -1;

    printf("%d\n", ans);



    return 0;
}
