#include <bits/stdc++.h>

using namespace std;

char s[100005];
char t[100005];
int pf[100005][26];
int n, m;

void p(){
    pf[0][t[0]-'a'] = 1;
    int j = 0;

    for(int i = 1; i < m; i++){
        for(int k = 0; k < 26; k++)
            pf[i][k] = pf[j][k];
        pf[i][t[i]-'a'] = i+1;

        j = pf[j][t[i]-'a'];
    }
    for(int k = 0; k < 26; k++)
        pf[m][k] = pf[j][k];
}

vector<vector<int> > dp;

int f(int i, int st){
    if(i == n) return (st == m);

    if(dp[i][st] != -1) return dp[i][st];

    if(s[i] == '?'){
        dp[i][st] = 0;
        for(int k = 0; k < 26; k++)
            dp[i][st] = max(dp[i][st], f(i+1, pf[st][k]) + (st == m));
        return dp[i][st];
    }    
    else return dp[i][st] = f(i+1, pf[st][s[i]-'a']) + (st == m);
}


int main(){

    scanf("%s %s", s, t);

    n = strlen(s), m = strlen(t);

    p();

    dp.assign(n+5, vector<int>(m+5, -1));

    printf("%d\n", f(0, 0));



    return 0;
}
