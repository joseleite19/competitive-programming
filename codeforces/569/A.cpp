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
const int N = 1000006;

int p[N], r[N];

int main(){

    for(int i = 2; i < N; i++) if(!p[i]){
        for(ll j = 1LL*i*i; j < N; j += i)
            p[i] = 1;
    }

    for1(i, N-1) p[i] = (!p[i]) + p[i-1];

    forn(i, 20) printf("%d %d\n", i, p[i]);


    return 0;
}
