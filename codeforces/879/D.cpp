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

int v[N], n, w;

int main(){

    ll k, m;
    scanf("%d %lld %lld", &n, &k, &m);

    forn(i, n) scanf("%d", v+i);

    bool eq = 1;

    forn(i, n-1) if(v[i] != v[i+1])
        eq = 0;

    if(eq){
        return printf("%lld\n", (m*n) % k), 0;
    }

    if(k >= n) return printf("%lld\n", n*m), 0;

    stack<pair<int, int> > s;

    forn(i, n){
        if(s.empty()){
            s.push(mp(v[i], 1));
            continue;
        }
        pair<int, int> t = s.top(); s.pop();
        if(t.ff == v[i]){
            t.ss++;
            if(t.ss >= k) t.ss -= k;
            if(t.ss > 0) s.ep(t.ff, t.ss);
        }
        else s.ep(t), s.ep(v[i], 1);
    }
    {
        int i = 0;
        while(!s.empty()){
            int x, a;
            tie(x, a) = s.top(); s.pop();
            while(a--) v[i++] = x;
        }
        n = i;
    }

    if(k >= n) return printf("%lld\n", n * m), 0;




    return 0;
}
