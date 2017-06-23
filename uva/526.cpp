#include <bits/stdc++.h>

using namespace std;

char s[111], t[111];
int n, m;
int dp[111][111], mark[111][111], pass;

int f(int i, int j){
    if(i > n || j > m) return 1000000000;
    if(i == n && j == m) return 0;
    if(mark[i][j] == pass) return dp[i][j];
    mark[i][j] = pass;
    if(i == n) return dp[i][j] = 1 + f(i, j+1);
    if(j == m) return dp[i][j] = 1 + f(i+1, j);
    int ans = 1000000000;
    if(s[i] == t[j]) ans = f(i+1, j+1);
    ans = min(ans, 1+min(min(f(i+1, j+1), f(i+1, j)), f(i, j+1)));
    return dp[i][j] = ans;
}

int main(){

    bool first = true;
    while(scanf("%[^\n]", s) != EOF){
        if(!first) printf("\n");
        first = false;
        getchar(); scanf("%[^\n]", t); getchar();
        n = strlen(s), m = strlen(t);

        pass++;
        printf("%d\n", f(0, 0));

        int i = 0, j = 0;

        int c = 1;
        int tmp = 0;
        while(i < n || j < m){
            if(f(i, j) == 1+f(i+1, j)){
                printf("%d Delete %d\n", c++, i+1 - tmp);
                tmp++;
                i++;
            }
            else if(f(i,j) == 1+f(i,j+1)){
                printf("%d Insert %d,%c\n", c++, i+1-tmp, t[j]);
                tmp--;
                j++;
            }
            else if(f(i,j) == f(i+1,j+1)){ i++; j++; }
            else if(f(i,j) == 1 + f(i+1,j+1)){
                printf("%d Replace %d,%c\n", c++, i+1-tmp, t[j]);
                i++; j++;
            }
            else assert(0);
        }

        s[0] = t[0] = 0;
    }



    return 0;
}
