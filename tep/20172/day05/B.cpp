#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
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
int vet[110];

ll C(ll n, ll k){
    memset(vet, 0, sizeof vet);
    for1(i, n) vet[i]++;
    for1(i, k) vet[i]--;
    for1(i, n-k) vet[i]--;
    ll a = 1, b = 1;
    for1(i, 102) if(vet[i]){
        while(vet[i] > 0) vet[i]--, a *= i;
        while(vet[i] < 0) vet[i]++, b *= i;
        ll g = __gcd(a, b);
        a /= g, b /= g;
    }
    return a / b;
}


int main(){
    ll n, m;

    while(scanf("%lld %lld", &n, &m) == 2 && n + m)
        printf("%lld things taken %lld at a time is %lld exactly.\n", n, m, C(n, m));


    return 0;
}
