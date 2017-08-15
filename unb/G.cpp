#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

char s[N], t[N];
int n;
int ps[N][26], pt[N][26];
int dp[N];

int f(int i){
    if(i == n) return 0;

    if(~dp[i]) return dp[i];

    if(s[i] == t[i]) return dp[i] = 1 + f(i+1);
    int ans = f(i+1);

    if(pt[i][ s[i]-'a'] < n) ans = max(ans, 1+f(pt[i][ s[i]-'a']+1));
    if(ps[i][ t[i]-'a'] < n) ans = max(ans, 1+f(ps[i][ t[i]-'a']+1));
    return dp[i] = ans;
}

int main(){

    memset(dp, -1, sizeof dp);

    int k;
    scanf("%s %d", s, &k);
    n = strlen(s);

    for(int i = 0; i < n; i++)
        t[n-1-i] = s[i];

    printf("%s %s\n", s, t);
    for(int c = 'a'; c <= 'z'; c++) for(int i = 0; i <= n; i++) pt[i][c] = ps[i][c] = n;

    for(int c = 0; c < 26; c++){
        for(int i = n-1; i >= 0; i--){
            ps[i][c] = ps[i+1][c];
            if(s[i+1]-'a' == c)
                ps[i][c] = i+1;
            pt[i][c] = pt[i+1][c];
            if(t[i+1]-'a' == c)
                pt[i][c] = i+1;
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d %d\n", i, ps[i]['i'-'a']);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d %d\n", i, pt[i]['i'-'a']);
    }
    printf("%d\n", f(0));

    return 0;
}
