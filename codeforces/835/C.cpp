#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

const int N = 100005;

int n, q, c;

int mat[115][115][15];

int main(){

    scanf("%d %d %d", &n, &q, &c);

    vector< pair<pair<int, int>, int> > start;
    for(int i = 0; i < n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        start.eb(mp(a, b), c);
    }

    for(int st = 0; st <= c; st++){
        for(int i = 0; i < n; i++){
            mat[ start[i].ff.ff ][ start[i].ff.ss ][st] += (start[i].ss + st) % (c+1);
        }
        for(int i = 0; i < 115; i++){
            for(int j = 0; j < 115; j++){
                if(i) mat[i][j][st] += mat[i-1][j][st];
                if(j) mat[i][j][st] += mat[i][j-1][st];
                if(i && j) mat[i][j][st] -= mat[i-1][j-1][st];
            }
        }
    }

    int t, x1, y1, x2, y2;
    while(q--){

        scanf("%d %d %d %d %d", &t, &x1, &y1, &x2, &y2);

        t %= (c+1);

        printf("%d\n", mat[x2][y2][t] - mat[x2][y1-1][t] - mat[x1-1][y2][t] + mat[x1-1][y1-1][t]);
        
    }



    return 0;
}
