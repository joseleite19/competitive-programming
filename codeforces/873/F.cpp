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

    forn(i, n) r[i].ff = s[i]-'a', r[i].ss = 0;
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

void build_lcp(){
    int k = 0;
    forn(i, n) r[ sa[i] ].ff = i;

    for(int i = 0; i < n; i++, k ? k-- : 0){
        if(r[i].ff == n-1){ k = 0; continue; }
        int j = sa[r[i].ff+1];
        while(i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
        lcp[r[i].ff] = k;
    }
}

int sum(int i, int j){
    if(i >= 0) return p[j] - p[i];
    return p[j];
}

int main(){

    scanf("%d %s %s", &n, s, f);

    reverse(s, s+n), reverse(f, f+n);

    forn(i, n) sa[i] = i;

    build_sa();
    build_lcp();

    forn(i, n){
        p[i] += (f[sa[i]] == '0');
        p[i+1] += p[i];
    }

    stack<int> w;

    forn(i, n){
        while(!w.empty() && lcp[w.top()] >= lcp[i]) w.pop();
        if(w.empty()) L[i] = -1;
        else L[i] = w.top();
        w.push(i);
    }
    while(!w.empty()) w.pop();

    ford(i, n){
        while(!w.empty() && lcp[w.top()] >= lcp[i]) w.pop();
        if(w.empty()) R[i] = n;
        else R[i] = w.top();
        w.push(i);
    }

    ll ans = 0;

    forn(i, n) if(f[i] == '0'){
        ans = n - i;
        break;
    }

    forn(i, n) ans = max(ans, 1LL * lcp[i] * sum(L[i], R[i]));

    printf("%lld\n", ans);
    //forn(i, n+1) printf(".%s.%d.[%d %d] %d %d\n", s+sa[i], lcp[i], L[i]+1, R[i], p[i], sum(L[i], R[i]));

    return 0;
}
