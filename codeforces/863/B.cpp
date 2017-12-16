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

int n, v[N];

int main(){

    scanf("%d", &n);

    forn(i, 2*n) scanf("%d", v+i);

    sort(v, v+2*n);

    int ans = 10000;
    forn(i, 2*n){
        forn(j, 2*n) if(i != j){
            int last = -1;
            int mx = 0;
            forn(k, 2*n) if(k != i && k != j){
                if(last == -1) last = v[k];
                else{
                    mx += v[k] - last;
                    last = -1;
                }
            }
            ans = min(ans, mx);
        }
    }

    printf("%d\n", ans);


    return 0;
}
