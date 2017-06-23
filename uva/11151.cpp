#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

int dp[N][N], mark[N][N], pass;
char s[N];
int n;

int f(int i, int j){
    if(j < i) return 0;
    if(i == j) return 1;
    if(i+1 == j) return s[i] == s[j] ? 2 : 1;
    if(mark[i][j] == pass) return dp[i][j];
    mark[i][j] = pass;

    if(s[i] == s[j]) return dp[i][j] = 2+f(i+1, j-1);
    return dp[i][j] = max(f(i+1, j), f(i, j-1));
}

int main(){
    int t;

    scanf("%d", &t); getchar();

    for(int tc = 1; tc <= t; tc++){
        scanf("%[^\n]", s); getchar();
        n = strlen(s);
        pass++;
        printf("%d\n", f(0, n-1)); s[0] = 0;
    }


    return 0;
}
