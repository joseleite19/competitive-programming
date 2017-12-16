#include <bits/stdc++.h>

#define MOD 1000000007LL

using namespace std;

const int N = 60;

typedef long long ll;

char s1[N], s2[N];;
int n;
int other(int a, int b){
    if(a != 1 && b != 1) return 1;
    if(a != 2 && b != 2) return 1;
    if(a != 3 && b != 3) return 1;
}

ll dp[100][5][5];
ll f(int i, int a, int b){
    if(i == n) return 1;

    ll &ans = dp[i][a][b];

    if(~ans) return ans;
    ans = 0;

    if(s1[i] == s2[i]){ // vertical
        for(int c = 1; c < 4; c++) if(c != a && c != b){
            ans = (ans + f(i+1, c, c)) % MOD;
        }
    }
    else{
        for(int c = 1; c < 4; c++) if(c != a){
            for(int c2 = 1; c2 < 4; c2++) if(c2 != c && c2 != b){
                ans = (ans + f(i+2, c, c2)) % MOD;
            }
        }
    }
    return ans;
}

int main(){


    scanf("%d %s %s", &n, s1, s2);

    memset(dp, -1, sizeof dp);
    printf("%lld\n", f(0, 0, 0));


    return 0;
}
