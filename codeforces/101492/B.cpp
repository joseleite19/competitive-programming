#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1000006;

char ans[N];

int main(){

    ll n;

    scanf("%lld", &n);

    ll qnt = n*(n+1)/2;

    if(qnt & 1) return printf("-1\n"), 0;

    qnt /= 2;

    for(int i = n; i >= 1; i--){
    	if(qnt >= i) ans[i] = '+', qnt -= i;
    	else ans[i] = '-';
    }

    printf("%s\n", ans+1);





    return 0;
}
