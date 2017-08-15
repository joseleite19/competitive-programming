#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

char mat[20][20];

bool h(int i, int j){
    if(j + 5 > 10) return false;
    int cnt = 0;
    for(int k = 0; k < 5; k++){
        if(mat[i][j+k] == 'X') cnt++;
        else if(mat[i][j+k] == 'O') cnt = -1000;
    }
    return cnt == 4;
}

bool v(int i, int j){
    if(i + 5 > 10) return false;
    int cnt = 0;
    for(int k = 0; k < 5; k++){
        if(mat[i+k][j] == 'X') cnt++;
        else if(mat[i+k][j] == 'O') cnt = -1000;
    }
    return cnt == 4;
}

bool d1(int i, int j){
    if(j + 5 > 10) return false;
    if(i + 5 > 10) return false;
    int cnt = 0;
    for(int k = 0; k < 5; k++){
        if(mat[i+k][j+k] == 'X') cnt++;
        else if(mat[i+k][j+k] == 'O') cnt = -1000;
    }
    return cnt == 4;
}

bool d2(int i, int j){
    if(j - 4 <  0) return false;
    if(i + 5 > 10) return false;
    int cnt = 0;
    for(int k = 0; k < 5; k++){
        if(mat[i+k][j-k] == 'X') cnt++;
        else if(mat[i+k][j-k] == 'O') cnt = -1000;
    }
    return cnt == 4;
}



int main(){

    for(int i = 0; i < 10; i++)
        scanf(" %s", mat[i]);

    bool win = false;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            win |= h(i, j);
            win |= v(i, j);
            win |= d1(i, j);
            win |= d2(i, j);
        }
    }

    printf("%s\n", win ? "YES" : "NO");


    return 0;
}
