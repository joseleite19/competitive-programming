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

int b[N];

int main(){
    int n, m, q;

    ll sum = 0;

    scanf("%d %d %d", &n, &m, &q);

    int x;

    forn(i, n){
        scanf("%d", &x);
        if(i & 1) sum -= x;
        else sum += x;
    }

    forn(i, m) scanf("%d", b+i);

    set<ll> s;

    {
        ll tmp = 0;
        forn(i, n) tmp += b[i] * (i & 1 ? -1: 1);
        s.insert(tmp);
        fore(i, n, m-1){
            // add i; rem i - n
            tmp -= b[i-n];
            tmp = - tmp;
            if(n & 1) tmp += b[i];
            else tmp -= b[i];
            s.insert(tmp);
        }
    }

    auto a = s.lower_bound(sum);
    ll ans = abs(sum - *a);
    if(a != s.begin())
        ans = min(ans, abs(sum - *prev(a)));
    printf("%lld\n", ans);

    int l, r;
    while(q--){
        scanf("%d %d %d", &l, &r, &x);
        if((r - l + 1) & 1){
            if(l & 1) sum += x;
            else sum -= x;
        }

        auto a = s.lower_bound(sum);
        ll ans = abs(sum - *a);
        if(a != s.begin())
            ans = min(ans, abs(sum - *prev(a)));
        printf("%lld\n", ans);
    }


    return 0;
}
