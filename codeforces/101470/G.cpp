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
const int N = 1005;

void file(){
    freopen("g.in", "r", stdin);
}

char s[N], t[N];
int n;
char a[N*20], b[N*20], c[N*20];

bitset<N*N*26> dp;

inline int id(int i, int j, char c){
    return N*26*i + 26*j + c;
}

int main(){
    file();

    scanf("%s", s);

    n = strlen(s);

    int sz = 0;
    while(scanf(" %s", t) == 1){
        if(isupper(t[1]))
            a[sz] = t[0]-'A', b[sz] = t[1]-'A', c[sz] = t[2]-'A', sz++;
        else{
            forn(i, n) if(s[i] == t[1]){
                dp[id(i, i, t[0]-'A')] = 1;
            }
        }
    }

    fore(l, 2, n){
        fore(s, 0, n-l){
            fore(p, 1, l-1){
                forn(k, sz){
                    if(dp[id(s, s+p-1, b[k])] && dp[id(s+p, s+l-1, c[k])])
                        dp[id(s, s+l-1, a[k])] = 1;
                }
            }
        }
    }

    printf("%d\n", (int)dp[id(0, n-1, 'S'-'A')]);
    
    return 0;
}
