#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 222;

int n, m;

char mat[N][N];

int main(){

    int cnt = 0;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf(" %s", mat[i]);

    int mnj = m, mni = n, mxj = -1, mxi = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == 'B'){
                cnt++;
                mxj = max(mxj, j);
                mxi = max(mxi, i);
                mnj = min(mnj, j);
                mni = min(mni, i);
            }
        }
    }

    if(!cnt) return printf("1\n"), 0;

    int mx = max(mxi - mni + 1, mxj - mnj + 1);

    if(mx > n || mx > m) return printf("-1\n"), 0;

    printf("%d\n", mx * mx - cnt);



    return 0;
}
