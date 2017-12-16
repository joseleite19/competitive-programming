#include <bits/stdc++.h>

using namespace std;

int mat[100][100];

int main(){

    int n, m;

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);

    long long ans = 0;

    for(int i = 0; i < n; i++){
        int one = 0, zero = 0;
        for(int j = 0; j < m; j++){
            if(mat[i][j]) one++;
            else zero++;
        }
        ans += (1LL << one)-1;
        ans += (1LL <<zero)-1;
    }

    for(int j = 0; j < m; j++){
        int one = 0, zero = 0;
        for(int i = 0; i < n; i++){
            if(mat[i][j]) one++;
            else zero++;
        }
        ans += (1LL << one)-1 - one;
        ans += (1LL <<zero)-1 - zero;
    }

    printf("%lld\n", ans);


    return 0;
}
