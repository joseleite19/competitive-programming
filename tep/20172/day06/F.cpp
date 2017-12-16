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
const int N = 22;
int fib[N];

int f(int x){
    if(x == 0) return 0;
    int id = 0;
    forn(i, N) if(fib[i] <= x) id = i;
    return fib[id+1] + f(x - fib[id]);
}

int main(){
    fib[1] = 1;
    fore(i, 2, N-1) fib[i] = fib[i-1] + fib[i-2];

    int n;

    while(scanf("%d", &n) == 1 && n){
        printf("%.2lf\n", fabs(1.6*n - f(n)));
    }

    return 0;
}
