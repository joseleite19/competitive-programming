#include <bits/stdc++.h>

using namespace std;

char s[111][55], t[111][55];

int ss[111], tt[111];

int n, m;

int dp[111][111], mark[111][111], pass;

int f(int i, int j){
    if(i == n && j == m) return 0;
    if(i == n) return 1*(m - j);
    if(j == m) return 5*(n - i);
    if(mark[i][j] == pass) return dp[i][j];
    mark[i][j] = pass;

    int ans = 1000000000;
    if(tt[i] == ss[j]) return dp[i][j] = f(i+1, j+1);

    //trocar
    ans = min(ans, 2 + f(i+1, j+1));

    //remover
    ans = min(ans, 1 + f(i, j+1));

    //inserir novo
    ans = min(ans, 5 + f(i+1, j));
    return dp[i][j] = ans;
}


int main(){

    int T;

    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++){
        int r;

        scanf("%d", &r);

        scanf("%d", &m);
        for(int i = 0; i < m; i++) scanf(" %s", s[i]);
        scanf("%d", &n);
        for(int i = 0; i < n; i++) scanf(" %s", t[i]);

        set<string> sss; map<string, int> rename;
        for(int i = 0; i < m; i++) sss.insert(s[i]);
        for(int i = 0; i < n; i++) sss.insert(t[i]);
        int ptr = 1;
        for(const string & x : sss)
            rename[x] = ptr++;
        for(int i = 0; i < m; i++) ss[i] = rename[ s[i] ];
        for(int i = 0; i < n; i++) tt[i] = rename[ t[i] ];

        pass++;
        int ans = f(0, 0);
        ans = ans * r * 50;
        printf("Caso #%d: R$ %d,%02d\n", tc, ans/100, ans % 100);
    }


    return 0;
}
