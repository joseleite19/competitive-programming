#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000007LL
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define for1(i, n) for(int i = 1; i <= int(n); i++)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int dp[100][2];

int f(int n, int l){
    if(n == 0) return 1;
    if(~dp[n][l]) return dp[n][l];
    if(l) return dp[n][l] = f(n-1, 0);
    return dp[n][l] = f(n-1, 0) + f(n-1, 1);
}

void print(int k, int i, int ja = 0){
    if(i < 0){ printf("\n"); return; }
    //printf("\n%d %d\n", f(i, 0), k);
    if(f(i, 0) > k){
        if(ja) printf("0");
        print(k, i-1, ja);
    }
    else{
        printf("1");
        print(k - f(i, 0), i-1, 1);
    }
}

int main(){
   
    memset(dp, -1, sizeof dp);

    int t;
    scanf("%d", &t);

    while(t--){
        int k;
        scanf("%d", &k);
        print(k, 39);
    }

    return 0;
}
