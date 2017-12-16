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


int main(){
    int n;

    scanf("%d", &n);

    multiset<int> s;

    forn(i, n){
        int x;
        scanf("%d", &x);
        s.insert(x);
    }

    ll ans = 0;
    while(s.size() >= 2){
        int a = *prev(s.end()), b = *s.begin();
        s.erase(s.find(a));
        s.erase(s.find(b));
        ans += b;
        a -= b;
        if(a) s.insert(a);
    }

    printf("%lld\n", ans);



    return 0;
}
