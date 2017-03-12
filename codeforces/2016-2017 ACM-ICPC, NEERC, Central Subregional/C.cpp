#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int h, w;

int mat[1003][1003];

int main(){

    scanf("%d %d", &h, &w);

	int a = 3*(h/3), b = 3*(w/3);

    int n = 3*a*b;
    int tmp = h;
    for(int i = 1; i <= h; i += 3){
        for(int j = 1; j <= w; j += 3){
            mat[i][j] = 1;
            mat[i+1][j] = 1;
            mat[i+1][j+1] = 1;
        }
    }

    if(h % 3 == 2){
        tmp = h - 2;
        for(int j = 1; j <= w; j++){
            mat[h-1][j] = 1;
        }
    }
    if(w % 3 == 2){
        for(int i = 1; i <= tmp; i++)
            mat[i][tmp-1] = 1;
    }

    n = 0;

    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            if(mat[i][j])
                n++;

    printf("%d\n", n);

    for(int i = 1; i <= h; i++)
        for(int j = 1; j <= w; j++)
            if(mat[i][j])
                printf("%d %d\n", i, j);


	return 0;
}
