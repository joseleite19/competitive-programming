#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

char s[N], t[N];

int n, m;
int dp[N][N], mark[N][N], pass;

int f(int i, int j){
    if(i == n || j == m) return 0;
    if(mark[i][j] == pass) return dp[i][j];
    mark[i][j] = pass;
    if(s[i] == t[j]) return dp[i][j] = 1 + f(i+1, j+1);
    return dp[i][j] = max(f(i+1, j), f(i, j+1));
}


int main(){

    while(scanf("%[^\n]", s) != EOF){
        getchar(); scanf("%[^\n]", t); getchar();
        pass++;
        n = strlen(s), m = strlen(t);
        printf("%d\n", f(0, 0));
        s[0] = t[0] = 0;
    }


    return 0;
}
