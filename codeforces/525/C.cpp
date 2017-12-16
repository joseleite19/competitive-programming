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

int n, v[N], p[N];

int main(){

    scanf("%d", &n);

    if(n < 4) return printf("0\n"), 0;

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    sort(v, v+n); reverse(v, v+n);

    ll a = 0, b = 0;
    ll ans = 0;
    for(int i = 0; i+1 < n; i++){
        if(v[i] == v[i+1] || v[i]-1 == v[i+1]){
            if(a == 0) a = v[i+1];
            else if(b == 0){
                b = v[i+1];
                ans += a * b;
                a = b = 0;
            }
            i++;
        }
    }

    printf("%lld\n", ans);

    return 0;
}
