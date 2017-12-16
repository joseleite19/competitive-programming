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
const int N = 200005;

ll x[N], y[N];

ll sq(ll x){
    return x * x;
}

int f(int i, int j, int k, int ii, int jj, int kk){
    ll a = sq(x[i] - x[j]) + sq(y[i] - y[j]);
    ll b = sq(x[k] - x[j]) + sq(y[k] - y[j]);
    ll c = sq(x[i] - x[k]) + sq(y[i] - y[k]); 
    ll A = sq(x[ii] - x[jj]) + sq(y[ii] - y[jj]);
    ll B = sq(x[kk] - x[jj]) + sq(y[kk] - y[jj]);
    ll C = sq(x[ii] - x[kk]) + sq(y[ii] - y[kk]);
    if(A*b*c != B*a*c) return 0;
    if(B*a*c != C*a*b) return 0;
    return 1;
}

int main(){

    for(int i = 0; i < 6; i++)
        scanf("%lld %lld", x+i, y+i);

    bool can = false;

    can |= f(0, 1, 2, 3, 4, 5);
    can |= f(0, 1, 2, 3, 5, 4);
    can |= f(0, 1, 2, 4, 3, 5);
    can |= f(0, 1, 2, 4, 5, 3);
    can |= f(0, 1, 2, 5, 3, 4);
    can |= f(0, 1, 2, 5, 4, 3);

    printf("%s\n", can ? "YES": "NO");

    return 0;
}
