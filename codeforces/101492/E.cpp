#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 100005;

int t[N];

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    	scanf("%d", t+i);

    sort(t, t+n);

    ll ans = 0;

    for(int i = n-1; i > 2; i -= 2){
        ans += t[1] + 3*t[0] + t[i];
    }

    if(n & 1) ans += t[0] + t[1] + t[2];
    else ans += t[1];

    printf("%lld\n", ans);


    return 0;
}
