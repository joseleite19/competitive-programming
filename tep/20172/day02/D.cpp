#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;

typedef long long ll;

ll dp[N];

ll f(ll n){
    if(n == 1) return 1;
    ll ans = 1 + 2*(n-1)*(n-1);
    //for(int i = 2; i <= n; i++)
    //    ans += 4*i;
    return ans;
}

int main(){

    int line = 1;
    int n = 1;

    int x;
    while(scanf("%d", &x) == 1){

        x = (x+1)/2;

        printf("%lld\n",3*f(x+1)-12);
    }


}
