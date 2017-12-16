#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int n, v[N];

int dp[N][2];

int f(int i, int last){
    int &ans = dp[i][last];
    if(~ans) return ans;
    if(i == n) return ans = 0;
    
    if(v[i] == 0 && last) return ans = f(i+1, last);
    return ans = max(f(i+1, last), 1+f(i+1, v[i]));
}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    memset(dp, -1, sizeof dp);

    printf("%d\n", f(0, 0));






    return 0;
}
