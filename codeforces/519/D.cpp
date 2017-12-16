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

int v[256];

char s[N];

map<ll, int> cnt[256];

int main(){

    forn(i, 26) scanf("%d", v+'a'+i);

    scanf("%s", s);

    ll p = 0, ans = 0;

    int n = strlen(s);
    forn(i, n-1){
        p += v[s[i]];
        //printf("%c %d %lld\n", s[i], v[s[i]], p);
        cnt[ s[i] ][p]++;
        ans += cnt[ s[i+1] ][p];
    }
    //forn(i, n-1) ans += s[i] == s[i+1];

    printf("%lld\n", ans);


    return 0;
}
