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
typedef tuple<int, int, int> ti;

const ll oo = 1000000000000000000;
const int N = 1000006;
const int B = 317;

int n;
ll v[N], t[N], k;
int a[N], b[N];
ll ans[N], now;

int cnt[N];

void addl(int x){
    now += cnt[a[x]];
    cnt[v[x]]++;
}

void addr(int x){
    now += cnt[b[x]];
    cnt[v[x]]++;
}

void reml(int x){
    cnt[v[x]]--;
    now -= cnt[a[x]];
}

void remr(int x){
    cnt[v[x]]--;
    now -= cnt[b[x]];
}

int main(){

    scanf("%d %lld", &n, &k);

    for1(i, n) scanf("%lld", t+i);

    for1(i, n){
        scanf("%lld", v+i);
        if(t[i] == 2) v[i] *= -1;
        v[i] += v[i-1];
    }

    {
        set<ll> s;
        forn(i, n+1) s.insert(v[i]), s.insert(v[i]+k), s.insert(v[i]-k);
        int p = 1;
        map<ll, int> go;
        for(ll x : s) go[x] = p++;
        forn(i, n+1) a[i] = go[ v[i]+k ], b[i] = go[ v[i]-k ], v[i] = go[ v[i] ];
    }


    int q;
    scanf("%d", &q);

    vector<ti> que;

    forn(i, q){
        int a, b;
        scanf("%d %d", &a, &b);
        que.eb(a-1, b, i);
    }

    sort(que.begin(), que.end(), [=](const ti &x, const ti &y){
        if(get<0>(x)/B != get<0>(y)/B)
            return get<0>(x)/B < get<0>(y)/B;
        return get<1>(x) < get<1>(y);
    });

    int L = 0, R = -1, x, y, id;

    forn(i, q){
        tie(x, y, id) = que[i];
        while(R < y) addr(++R);
        while(L > x) addl(--L);
        while(L < x) reml(L++);
        while(R > y) remr(R--);
        ans[id] = now;
    }

    forn(i, q) printf("%lld\n",  ans[i]);
    

    return 0;
}
