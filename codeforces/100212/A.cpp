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

const ll oo = 100000000000000000;
const int N = 10000006;

void file(){
    freopen("bomb.in", "r", stdin);
    freopen("bomb.out", "w", stdout);
}

ll x[3], y[3];

ll sq(ll x){
    return x * x;
}

double f(int i, int j){
    return sqrt(sq(x[i] - x[j]) + sq(y[i] - y[j]));
}


int main(){

    file();

    forn(i, 3) scanf("%lld %lld", x+i, y+i);

    double a[3];
    a[2] = f(0, 1);
    a[0] = f(1, 2);
    a[1] = f(2, 0);

    double r[3];

    int mx = 0;
    forn(i, 3) if(a[i] > a[mx]) mx = i;

    if(a[mx] + 1e-9 > (a[1] + a[2] + a[0]) / 2){
        r[mx] = 0;
        if(mx == 0){
            r[1] = a[1];
            r[2] = a[mx] - r[1];
        }
        if(mx == 1){
            r[0] = a[0];
            r[2] = a[mx] - r[0];
        }
        if(mx == 2){
            r[1] = a[1];
            r[0] = a[mx] - r[0];
        }
    }
    else{
        double tot = 0;
        forn(i, 3) tot += a[i]*0.5;
        forn(i, 3){
            r[i] = tot - a[i];
        }
    }

    forn(i, 3) printf("%.20lf\n", r[i]);


    return 0;
}
