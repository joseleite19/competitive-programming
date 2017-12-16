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
const int N = 5005;

int vis[N][N];

int main(){

    int n, t, x, y;

    scanf("%d", &t);

    for1(tc, t){
        vector<pair<int, int> > v;

        scanf("%d", &n);

        forn(i, n) scanf("%d %d", &x, &y), v.eb(x, y);

        {
            set<int> xx, yy;
            forn(i, n) xx.insert(v[i].ff), yy.insert(v[i].ss);
            map<int, int> gx, gy;
            int px = 1, py = 1;
            for(auto x : xx) gx[x] = px++;
            for(auto y : yy) gy[y] = py++;
            forn(i, n) v[i].ff = gx[ v[i].ff ],
                       v[i].ss = gy[ v[i].ss ];
        }

        forn(i, n) vis[ v[i].ff ][ v[i].ss ] = tc;

        sort(all(v));

        int ans = 0;
        forn(i, n){
            fore(j, i+1, n-1){
                if(v[i].ff == v[j].ff) continue;
                if(v[i].ss == v[j].ss) continue;
                if(vis[ v[i].ff ][ v[j].ss ] == tc &&
                   vis[ v[j].ff ][ v[i].ss ] == tc)
                    ans++;
            }
        }
        printf("Case %d: %d\n", tc, ans / 2);
    }


    return 0;
}
