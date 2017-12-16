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

int f(int a, int b){
    if(a == 0 || b == 0) return 1;
    if(a == b) return f(a-1, b);
    return f(a-1, b) + f(a, b-1);
}

int g(int a, int b){
    if(a == 0 && b == 0) return 1;
    if(a == 0 || b == 0) return 0;
    if(a == b) return 1 + g(a-1, b);
    return g(a-1, b) + g(a, b-1);
}

int main(){

    int n, m;
    scanf("%d %d", &n, &m);

    printf("%d %d\n", f(n, m), g(n, m));

    return 0;
}
