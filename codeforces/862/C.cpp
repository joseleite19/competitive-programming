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

int v[N];

int main(){
    int n, x;

    scanf("%d %d", &n, &x);

    //int j = 0;
    //while(x) v[j++] = x & 1, x /= 2;
    //reverse(v, v+j);

    set<pair<int, int> > s;
    s.insert(mp(n, 0));

    forn(i, 20){
        int k = 1 << i;
        set<pair<int, int> > ss;
        int b = 0;
        for(auto x : s){
            ss.insert(mp(x.ff - x.ff / 2, x.ss));
            if(x.ff / 2) ss.insert(mp(x.ff / 2, x.ss + k));
            b += x.ff / 2;
        }
        if((b & 1) != (!!(x & k))){
            int go = 0;
            for(auto x : s) if(x.ff >= 2){
                int a = x.ff - x.ff / 2;
                int b = x.ff / 2;
                a--, b++;
                if(b == x.ff) continue;
                ss.erase(mp(x.ff - x.ff / 2, x.ss));
                if(x.ff / 2) ss.erase(mp(x.ff / 2, x.ss + k));
                
                if(a) ss.insert(mp(a, x.ss));
                ss.insert(mp(b, x.ss + k));
                go = 1;
                break;
            }
            if(!go){
                for(auto x : s) if(x.ff == 1){
                    ss.erase(mp(x.ff - x.ff / 2, x.ss));
                    if(x.ff / 2) ss.erase(mp(x.ff / 2, x.ss + k));
                    int a = x.ff - x.ff / 2;
                    int b = x.ff / 2;
                    a--, b++;
                    if(a) ss.insert(mp(a, x.ss));
                    ss.insert(mp(b, x.ss + k));
                    go = 1;
                    break;
                }
                if(!go) for(auto x : s){
                    ss.erase(mp(x.ff - x.ff / 2, x.ss));
                    if(x.ff / 2) ss.erase(mp(x.ff / 2, x.ss + k));
                    int a = x.ff - x.ff / 2;
                    int b = x.ff / 2;
                    a--, b++;
                    if(a) ss.insert(mp(a, x.ss));
                    ss.insert(mp(b, x.ss + k));
                    go = 1;
                    break;
                }
            }
        }
        swap(s, ss);
    }

    for(auto x : s) if(x.ff > 1){
        return printf("NO\n"), 0;
    }

    printf("YES\n");

    for(auto x : s) printf("%d ", x.ss);
    printf("\n");


    return 0;
}
