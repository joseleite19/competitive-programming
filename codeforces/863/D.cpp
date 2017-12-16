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
const int N = 200005;

int n, v[N], q, m;
vector<tuple<int, int, int> > t;

int main(){
    scanf("%d %d %d", &n, &q, &m);
    
    forn(i, n) scanf("%d", v+i);

    forn(i, q){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        t.eb(a, b, c);
    }

    int x, a, b, c;
    while(m--){
        scanf("%d", &x);

        ford(i, q){
            tie(a, b, c) = t[i];
            if(b <= x && x <= c){
                if(a == 1) x = (x == b ? c : x - 1);
                else x = c - (x - b);
            }
        }
        printf("%d ", v[x-1]);
    }
    printf("\n");




    return 0;
}
