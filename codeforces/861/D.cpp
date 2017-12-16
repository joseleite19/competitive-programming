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
const int N = 70007;

int b(char c){
    return c - '0' + 1;
}

map<ll, set<int> > cnt;

char s[N][11];

ll tab[N][11][11];

int main(){

    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf(" %s", s[i]);
        for(int j = 0; j < 9; j++){
            ll hs = 0;
            for(int k = j; k < 9; k++){
                hs = 11 * hs + b(s[i][k]);
                tab[i][j][k] = hs;
                if(cnt.count(hs) && cnt[hs].size() >= 5) continue;
                cnt[hs].insert(i);
            }
        }
    }

    int found = 0;
    ll tmp;
    for(int i = 0; i < n; i++){
        found = 0;
        for(int sz = 1; sz <= 9 && !found; sz++){
            for(int j = 0; j <= 9 - sz; j++){
                tmp = tab[i][j][j+sz-1];
                if(cnt[tmp].size() == 1){
                    found = 1;
                    for(int k = j; k < j + sz; k++)
                        printf("%c", s[i][k]);
                    break;
                }
            }
        }
        printf("\n");
    }



    return 0;
}
