#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

const int N = 1000006;

int n, a;

int c[N];

int v[N];

int main(){

    scanf("%d %d", &n, &a);

    for(int i = 0; i < n; i++)
        scanf("%d", c+i);

    int cnt = 0;

    map<int, set<int> > ans;

    for(int i = 0; i < n; i++) if(c[i] != a) ans[0].insert(c[i]);

    for(int i = 0; i < n; i++){
        if(c[i] == a){
            cnt++;
            while(!ans.empty()){
                if(ans.begin()->ff < cnt) ans.erase(ans.begin());
                else break;
            }
        }
        else{
            if(!ans.count(v[ c[i] ])) continue;
            if(!ans[ v[ c[i] ] ].count(c[i])) continue;
            ans[ v[ c[i] ] ].erase(c[i]);
            if(ans[ v[ c[i] ] ].size() == 0)
                ans.erase(v[ c[i] ]);
            v[ c[i] ]++;
            ans[ v[ c[i] ] ].insert(c[i]);
        }
        if(ans.empty()) break;
    }

    while(!ans.empty()){
        if(ans.begin()->ss.empty())
            ans.erase(ans.begin());
        else break;
    }

    if(ans.empty()) return printf("-1\n"), 0;

    printf("%d\n", *ans.begin()->ss.begin());





    return 0;
}
