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
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define ford(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, a, b) for(int i = int(a); i <= int(b); ++i)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000LL;
const int N = 1000006;

int n;
char s[N];
int sa[N], tsa[N], lcp[N], r[N], nr[N], c[N];

void sort(int k, int mx){
    mx += 3;
    memset(c, 0, sizeof(int)*mx);
    forn(i, n) c[i + k < n ? r[i+k]+1 : 1]++;
    partial_sum(c, c+mx, c);
    int t;
    forn(i, n) t = sa[i]+k < n ? r[ sa[i]+k ] : 0,
               tsa[ c[t]++ ] = sa[i];
    memcpy(sa, tsa, sizeof(int) * n);
}

void build_sa(){

    forn(i, n) sa[i] = i, r[i] = s[i];

    int t = 300, a, b;
    for(int sz = 1; sz < n; sz *= 2){
        sort(sz, t), sort(0, t);
        t = nr[ sa[0] ] = 0;
        for1(i, n-1){
            a = sa[i]+sz < n ? r[ sa[i]+sz ] : 0;
            b = sa[i-1]+sz < n ? r[ sa[i-1]+sz ] : 0;
            nr[ sa[i] ] = r[ sa[i] ] == r[ sa[i-1] ] && a == b ? t : ++t;
        }
        if(t == n-1) break;
        memcpy(r, nr, sizeof(int) * n);
    }
}

void build_lcp(){ // lcp[i] = lcp(s[:i], s[:i+1])
    int k = 0;
    forn(i, n) r[ sa[i] ] = i;

    forn(i, n){
        if(r[i] == n-1) k = 0;
        else{
            int j = sa[r[i]+1];
            while(i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
        }
        lcp[r[i]] = k;
        if(k) k--;
    }
}

int main(){


    int t;

    scanf("%d", &t);

    while(t--){

        scanf("%d %s", &n, s);

        forn(i, n) s[n+i] = s[i];
        n += n;
        s[n++] = '$';

        build_sa(), build_lcp();

        //forn(i, n) printf(".%s. %d %d\n", s+sa[i], sa[i], lcp[i]);

        int ans = 0, found = 0;

        forn(i, n){
            if(sa[i] < n/2){
                if(!found){
                    ans = sa[i];
                    found = true;
                }
                else{
                    ans = min(ans, sa[i]);
                }
                if(lcp[i] < n/2) break;
            }
            else if(found) break;
        }

        printf("%d\n", ans);

    }

    return 0;
}
