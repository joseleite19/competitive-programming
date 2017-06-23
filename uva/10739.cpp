#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int dp[N][N], mark[N][N], pass;
char s[N];
int n;

int f(int i, int j){
    if(j <= i) return 0;
    if(i+1 == j) return s[i] != s[j];
    if(mark[i][j] == pass) return dp[i][j];
    mark[i][j] = pass;

    if(s[i] == s[j]) return dp[i][j] = f(i+1, j-1);
    return dp[i][j] = 1 + min(min(f(i+1, j), f(i, j-1)), f(i+1, j-1));
}

int main(){
    int t;

    scanf("%d", &t);

    for(int tc = 1; tc <= t; tc++){
        scanf(" %s", s);
        n = strlen(s);
        pass++;
        printf("Case %d: %d\n", tc, f(0, n-1));
    }


    return 0;
}
