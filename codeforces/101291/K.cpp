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

int a[10], b[10];

int main(){

    forn(i, 6) scanf("%d", a+i);
    forn(i, 6) scanf("%d", b+i);

    int eq = 0, gt = 0;

    forn(i, 6) forn(j, 6){
        if(a[i] == b[j]) eq++;
        if(a[i] > b[j]) gt++;
    }

    printf("%.5lf\n", eq != 36 ? 1.0 * gt / (36 - eq) : 0);



    return 0;
}
