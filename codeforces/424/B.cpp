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

ll x[N], y[N], k[N];

vector<pair<ll, int> > v;

int main(){

    int n, s;

    scanf("%d %d", &n, &s);

    for(int i = 0; i < n; i++){
        scanf("%lld %lld %lld", x+i, y+i, k+i);
        v.eb(x[i] * x[i] + y[i] * y[i], k[i]);
    }

    sort(v.begin(), v.end());

    int i = 0;
    while(i < n && s < 1000000){
        s += v[i].ss;
        i++;
    }

    if(s < 1000000) return printf("-1\n"), 0;

    printf("%.20lf\n", sqrt(v[i-1].ff));



    return 0;
}
