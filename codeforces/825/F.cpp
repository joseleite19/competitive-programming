#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 8003;

int n;
int p[N], mat[N][N];
char s[N];

void pf(int start){
    p[0] = -1;
    int j = -1;
    for(int i = 0; i < n - start; i++){
        while(j >= 0 && s[i+start] != s[j+start]) j = p[j];
        j++;
        p[i+1] = j;
    }
}

int dp[N], dp1[N];

int conv(int x){
    if(~dp1[x]) return dp1[x];
    int ans = 0, v = x;
    while(v) ans++, v /= 10;
    return dp1[x] = ans;
}

void prep(){
    int tmp;
    for(int i = 0; i < n; i++){
        pf(i);
        for(int j = i; j < n; j++){
            tmp = (j - i + 1) - p[j+1-i];
            if((j - i + 1) % tmp == 0) mat[i][j] = tmp;
            else mat[i][j] = (j-i+1);
        }
    }
}

int f(int i){
    if(i == n) return 0;

    if(~dp[i]) return dp[i];

    dp[i] = 1000000000;

    for(int j = i; j < n; j++){
        dp[i] = min(dp[i], conv((j-i+1)/mat[i][j]) + mat[i][j] + f(j+1));
    }
    return dp[i];
}

int main(){

    scanf("%s", s);
    n = strlen(s);

    memset(dp, -1, sizeof dp);
    memset(dp1, -1, sizeof dp1);

    prep();

    printf("%d\n", f(0));



    return 0;
}
