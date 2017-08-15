#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back
#define pb push_back

using namespace std;

int main(){
    int n;

    while(scanf("%d", &n) == 1 && n){
        long long ans = 0;
        for(; n > 0; n--){
            ans += 1LL*n*n;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
