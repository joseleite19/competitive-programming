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
const int N = 1000000000;
//static int d[N+1];

int f(int x){
    int ans = 0;
    for(ll i = 1; i*i <= x; i++) if(x % i == 0){
        ans++;
        if(i != x / i) ans++;
    }
    return ans;
}

int main(){

    int mx = 0;

    for1(i, N) mx = max(mx, f(i));

    printf("%d\n", mx);



    return 0;
}
