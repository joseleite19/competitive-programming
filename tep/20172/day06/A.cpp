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

ll C(int n, int k){
    ll num = 1, den = 1;

    //n! / (n-k)! / k!
    
    fore(i, n-k+1, n){
        if(k) den *= k;
        num *= i;
        ll g = __gcd(num, den);
        if(g) num /= g, den /= g;
    }
    return num / den;
}

int main(){

    int n, m;

    for(int tc = 1; scanf("%d %d", &n, &m) == 2 && n; tc++){
        set<ll> s;

        ll x;

        forn(i, n){
            scanf("%lld", &x);
            s.insert(x);
        }

        printf("Case %d:\n", tc);
        forn(i, m){
            scanf("%lld", &x);
            printf("%lld\n", C(s.size()+x-1, x));
        }

    }


    return 0;
}
