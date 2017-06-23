#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int v[N], n;

long long dp[N][4];

long long C(int n, int k){
    if(n == k || k == 0 || n == 0) return 1;
    if(~dp[n][k]) return dp[n][k];
    return dp[n][k] = C(n-1, k) + C(n-1, k-1);
}

int main(){
    
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    sort(v, v+n);

    long long cnt = 1;
    for(int i = 3; i < n; i++)
        if(v[i] == v[2])
            cnt++;

    long long ans;
    
    if(v[0] == v[1] && v[1] == v[2]){
        cnt += 2;
        ans = cnt * (cnt-1) * (cnt-2) / 6;
    }
    else if(v[0] == v[1]){
        ans = cnt;
    }
    else if(v[1] == v[2]){
        cnt++;
        ans = cnt * (cnt-1) / 2;
    }
    else ans = cnt;

    printf("%lld\n", ans);



    return 0;
}
