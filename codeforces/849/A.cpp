#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;
int n, v[N];
int dp[111][111];

int f(int i, int qnt){
    if(i == n) return qnt & 1;
    int &ans = dp[i][qnt];
    if(~ans) return ans;

    ans = 0;
    for(int j = i; j < n; j += 2){
        if(v[i] & 1){
            if(v[j] & 1){
                ans |= f(j+1, qnt+1);
            }
        }
    }
    return ans;
}


int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    memset(dp, -1, sizeof dp);

    printf("%s\n", f(0, 0) ? "Yes" : "No");


    return 0;
}
