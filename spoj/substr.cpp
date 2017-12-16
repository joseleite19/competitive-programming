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

const ll oo = 1000000000000000000LL;
const int N = 1000006;

int n;
char s[N], f[N];
int sa[N], lcp[N], p[N], L[N], R[N];
pair<int, int> r[N];

void sort(){
    sort(sa, sa+n, [=](const int &a, const int &b){
        return r[a] < r[b];       
    });
}

void build_sa(){

    forn(i, n) sa[i] = i, r[i].ff = s[i], r[i].ss = 0;
    sort();

    for(int sz = 1; sz < n; sz *= 2){
        pair<int, int> last = r[ sa[0] ];
        r[ sa[0] ].ff = 0;
        for1(i, n-1){
            if(r[ sa[i] ] == last) r[ sa[i] ].ff = r[ sa[i-1] ].ff;
            else{
                last = r[ sa[i] ];
                r[ sa[i] ].ff = r[ sa[i-1] ].ff+1;
            }
        }
        forn(i, n){
            if(sa[i] + sz < n) r[ sa[i] ].ss = r[ sa[i]+sz ].ff;
            else r[ sa[i] ].ss = -1;
        }
        sort();
    }
}

// lcp[i] = lcp(s[:i], s[:i+1])
void build_lcp(){
    int k = 0;
    forn(i, n) r[ sa[i] ].ff = i;

    for(int i = 0; i < n; i++, k ? k-- : 0){
        if(r[i].ff == n-1) k = 0;
        else{
            int j = sa[r[i].ff+1];
            while(i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
        }
        lcp[r[i].ff] = k;
    }
}

int main(){

    int t;

    scanf("%d", &t);

    while(t--){
        scanf("%s", s);
        n = strlen(s);

        build_sa(), build_lcp();

        int ans = 0;
        forn(i, n) ans += (n - sa[i]) - lcp[i];
        printf("%d\n", ans);
    }


    return 0;
}
