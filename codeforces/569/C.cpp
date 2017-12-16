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
const int N = 40000007;

bitset<N> p, r;

int v[30];

bool palin(int x){
    int sz = 0;
    while(x) v[sz++] = x % 10, x /= 10;
    if(!sz) return 0;
    for(int i = 0; i < sz/2; i++) if(v[i] != v[sz-1-i])
        return 0;
    return 1;
}


int main(){

    p.set();
    p.reset(0), p.reset(1);
    for(int i = 2; i < N; i++) if(p[i]){
        for(ll j = 1LL*i*i; j < N; j += i)
            p.reset(j);
    }

    for(int i = 1; i < N; i++){
        if(palin(i))
            r.set(i);
    }

    ll a, b;
    scanf("%lld %lld", &a, &b);

    int ans = 0;
   
    ll pp = 0, rr = 0;
    for(int i = 1; i < N; i++){
        if(p[i]) pp++;
        if(r[i]) rr++;
        if(pp * b <= a * rr) ans = i;
    }
    if(ans == 0 || ans == N-1) printf("Palindromic tree is better than splay tree\n");
    else printf("%d\n", ans);

    return 0;
}
