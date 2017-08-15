#include <bits/stdc++.h>

using namespace std;

int n;
char s[222];

// 0 set
// 1 elementlist
// 2 list
// 3 element
// 4 atom
int dp[222][222][6];
int mark[222][222][6], pass;

int f(int i, int j, int r){

    if(mark[i][j][r] == pass) return dp[i][j][r];
    mark[i][j][r] = pass;

    if(r == 4){
        if(j != i) return dp[i][j][r] = 0;
        return dp[i][j][r] = 1;
    }

    if(r == 0){
        if(i > j) return dp[i][j][r] = 0;
        if(s[i] != '{') return dp[i][j][r] = 0;
        if(s[j] != '}') return dp[i][j][r] = 0;
        return dp[i][j][r] = f(i+1, j-1, 1);
    }

    if(r == 1){
        if(i == j+1) return dp[i][j][r] = 1;
        return dp[i][j][r] = f(i, j, 2);
    }

    if(r == 2){
        if(i > j) return dp[i][j][r] = 0;
        if(f(i, j, 3)) return dp[i][j][r] = 1;
        
        for(int k = i+1; k < j; k++){
            if(s[k] != ',') continue;
            if(f(i, k-1, 3) && f(k+1, j, 2))
                return dp[i][j][r] = 1;
        }
        return dp[i][j][r] = 0;
    }

    if(r == 3){
        if(i > j) return dp[i][j][r] = 0;
        if(f(i, j, 4)) return dp[i][j][r] = 1;
        return dp[i][j][r] = f(i, j, 0);
    }
}

int main(){
    int t;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        scanf(" %s", s);
        n = strlen(s);
        pass++;
        printf("Word #%d: %s\n", tc, f(0, n-1, 0) ? "Set" : "No Set");
    }
}
