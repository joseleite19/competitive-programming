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
#define fore(i, n) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;


int main(){
    ll n, k;

    scanf("%lld %lld", &n, &k);

    int d = 0, t = 0;

    ll x = n;

    while(x % 2 == 0) d++, x /= 2;
    while(x % 5 == 0) t++, x /= 5;

    while(t < k) n *= 5, t++;
    while(d < k) n *= 2, d++;

    printf("%lld\n", n);


    return 0;
}
