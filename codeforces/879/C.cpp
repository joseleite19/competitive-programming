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

int f(int x){
    x |= 3;
    x ^= 2;
    return x;
}

int f2(int x){
    return (x & 1021) | 1;
}

int v[10]; // 0 = b; 1 = !b; 2 = 0; 3 = 1;
int main(){

    int n;

    scanf("%d", &n);

    char c;
    int x;
    forn(i, n){
        scanf(" %c %d", &c, &x);
        if(c == '|'){
            forn(i, 10) if(x & (1 << i)){
                v[i] = 3;
            }
        }
        else if(c == '&'){
            forn(i, 10){
                if(x & (1 << i));
                else{
                    v[i] = 2;
                }
            }
        }
        else if(c == '^'){
            forn(i, 10){
                if(x & (1 << i)){
                    if(!v[i]) v[i] = 1;
                    else if(v[i] == 1) v[i] = 0;
                    else if(v[i] == 2) v[i] = 3;
                    else if(v[i] == 3) v[i] = 2;
                }
            }
        }
    }

    vector<pair<char, int> > ans;

    x = 0;

    forn(i, 10) if(v[i] == 1) x |= 1 << i;

    if(x) ans.eb('^', x);

    x = 1023;

    forn(i, 10) if(v[i] == 2) x &= ~(1 << i);

    if(x != 1023) ans.eb('&', x);

    x = 0;

    forn(i, 10) if(v[i] == 3) x |= 1 << i;

    if(x) ans.eb('|', x);

    printf("%d\n", int(ans.size()));

    forn(i, ans.size()) printf("%c %d\n", ans[i].ff, ans[i].ss);


    return 0;
}
