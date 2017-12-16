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
int dp[N];

char ans[N];

int f(int val){
    if(!val) return 0;
    int &x = dp[val];
    if(~x) return x;
    x = 1000000000;
    for(int i = 0; i < n && v[i] <= val; i++){
        x = min(x, 1+f(val - v[i]));
    }
    return x;
}

int f2(int val){
    int ans = 0;

    for(int i = n-1; i >= 0; i--){
        while(val >= v[i]){
            ans++;
            val -= v[i];
        }
    }
    return ans;
}

int main(){

    memset(dp, -1, sizeof dp);

    for(int i = 2; ; i++){
        int q = i * (i-1)/2;
        if(q >= N) break;
        v[n++] = q;
    }

    int k;
    scanf("%d", &k);

    if(k == 0) return printf("a\n"), 0;

    f(k);

    char nx = 'a';
    int q = 0;
    while(k){
        for(int i = 0; i < n && v[i] <= k; i++) if(f(k) == 1+f(k-v[i])){
            for(int j = 0; j < i+2; j++) ans[q+j] = nx;
            nx++;
            q += i+2;
            k -= v[i];
            break;
        }
    }

    printf("%s\n", ans);



    return 0;
}
