#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 102;

int mat[N][N];

int n, m;

int main(){

    vector<pair<int, int> > v;

    scanf("%d %d", &n, &m);

    int inv = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    if(n > m){
        inv = 1;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < i; j++)
                swap(mat[i][j], mat[j][i]);
        swap(n, m);
    }

    while(1){
        int t = -1, e = -1, mm = -1;
        for(int i = 0; i < n; i++){
            int mn = 100000000;
            for(int j = 0; j < m; j++)
                mn = min(mn, mat[i][j]);
            if(mn){
                t = inv, e = i, mm = mn;
                break;
            }
        }
        
        if(t == -1){
            for(int j = 0; j < m; j++){
                int mn = 10000000;
                for(int i = 0; i < n; i++)
                    mn = min(mn, mat[i][j]);
                if(mn){
                    t = inv^1, e = j, mm = mn;
                }
            }
            if(t == -1) break;
        }
        for(int i = 0; i < mm; i++) v.push_back(mp(t, e));
        if(t == inv) for(int j = 0; j < m; j++) mat[e][j] -= mm;
        if(t == inv^1) for(int i = 0; i < n; i++) mat[i][e] -= mm;
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(mat[i][j])
                return printf("-1\n"), 0;

    printf("%d\n", int(v.size()));

    for(int i = 0; i < v.size(); i++)
        printf("%s %d\n", v[i].ff == 0 ? "row" : "col", v[i].ss+1);

}
