#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int mat[4][4];

int main(){

    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            scanf("%d", &mat[i][j]);

    bool can = false;

    for(int i = 0; i < 4; i++){
        if(mat[i][3] && (mat[i][0] || mat[i][1] || mat[i][2] || mat[(i+2)%4][1]))
            can = true;
        if(mat[i][0] && mat[(i-1+4)%4][3]) can = true;
        if(mat[i][2] && mat[(i+1)%4][3]) can = true;
    }

    printf("%s\n", can ? "YES" : "NO");

    return 0;
}
