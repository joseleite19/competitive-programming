#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char s[100];
int n;

ll dp1[100][100][20][2];
ll dp[100][100][20][2];

ll f1(int i, int len, int last, bool fall, bool zero){
    if(i == len) return 1;

    ll &ans = dp1[i][len][last][fall];

    if(~ans) return ans;
    ans = 0;

    for(int d = 0 + zero; d < 10; d++){
        if(fall){
            if(d > last) continue;
            ans += f1(i+1, len, d, fall, 0);
        }
        else{
            if(d < last) ans += f1(i+1, len, d, 1, 0);
            else ans += f1(i+1, len, d, 0, 0);
        }
    }
    return ans;
}




bool check(int i, bool fall){
    if(i == n) return true;
    if(fall){
        if(s[i] > s[i-1]) return false;
        return check(i+1, fall);
    }
    if(s[i] < s[i-1]) return check(i+1, 1);
    return check(i+1, 0);
}

int main(){

    memset(dp1, -1, sizeof dp1);

    int t;

    scanf("%d", &t);

    while(t--){
        scanf(" %s", s);
        n = strlen(s);

        for(int i = 0; i < n; i++) s[i] -= '0';

        if(!check(1, 0)){
            printf("-1\n");
            continue;
        }

        ll ans = 0;

        for(int i = 0; i < n; i++)
            ans += f1(0, i, 0, 0, 1);

        for(int d = 1; d < s[0]; d++)
            ans += f1(0, n, 0, 0, d);

        bool fall = false;
        for(int i = 1; i < n; i++){
            for(int d = 0; d < s[i]; d++)
                ans += f1(i+1, n, d, (d < s[i-1]) || fall, 0);
            if(s[i] < s[i-1]) fall = true;
        }

        printf("%lld\n", ans);
    }


    return 0;
}
