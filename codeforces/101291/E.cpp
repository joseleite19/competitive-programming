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

int n, v[N];

int main(){
    int k;

    scanf("%d %d", &n, &k);

    forn(i, n) scanf("%d", v+i);

    multiset<int> s;

    forn(i, k) s.insert(v[i]);

    ll ans = 0, t = 0;

    for(int i = k; i < n; i++){
        ans += t + *s.begin();
        t += *s.begin();
        s.erase(s.begin());
        s.insert(v[i]);
    }

    while(!s.empty()){
        ans += t + *s.begin();
        t += *s.begin();
        s.erase(s.begin());
    }

    printf("%lld\n", ans);



    return 0;
}
