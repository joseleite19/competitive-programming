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
const int N = 200005;

int n, v[N];

int main(){

    scanf("%d", &n);

    forn(i, n) scanf("%d", v+i);

    if(n == 1) return printf("0\n"), 0;
    if(n <= 3){
        ll sum = 0;
        forn(i, n) sum += v[i];
        return printf("%lld\n", sum), 0;
    }

    ll sum = 0, ans = 0;

    priority_queue<ll> q;
    forn(i, n) sum += v[i], q.push(-v[i]);

    while(q.size() > 3){
        int l = 2;
        if(q.size() & 1) l = 3;
        sum = 0;
        forn(i, l) sum -= q.top(), q.pop();
        ans += sum;
        q.push(-sum);
    }

    while(!q.empty()) ans -= q.top(), q.pop();

    printf("%lld\n", ans);

    return 0;
}
