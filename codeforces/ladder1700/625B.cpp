#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

char s[N], t[33];
int mat[33][33];

int n, m;

void p(){
    int j = 0;
    mat[0][ t[0]-'a' ] = 1;
    for(int i = 1; i < m; i++){
        for(int k = 0; k < 26; k++) mat[i][k] = mat[j][k];
        mat[i][ t[i]-'a' ] = i+1;
        j = mat[j][ t[i]-'a'];
    }
}

int dp[N][33];

int f(int i, int j){
    if(j == m) return 1000000000;
    if(i == n) return 0;


    if(~dp[i][j]) return dp[i][j];

    return dp[i][j] = min(1+f(i+1, 0), f(i+1, mat[j][s[i]-'a']));
}


int main(){

    scanf("%s %s", s, t);
    n = strlen(s), m = strlen(t);

    p();

    memset(dp, -1, sizeof dp);
    printf("%d\n", f(0, 0));



}
