#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int mat[100][100];
int n;

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == 1) continue;
            bool can = false;
            for(int k = 0; k < n; k++){
                for(int l = 0; l < n; l++){
                    if(mat[i][k] + mat[l][j] == mat[i][j])
                        can = true;
                }
            }
            if(!can) return printf("No\n"), 0;
        }
    }

    printf("Yes\n");

    return 0;
}
