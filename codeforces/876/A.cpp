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


int main(){
    int n, a, b, c;

    scanf("%d %d %d %d", &n, &a, &b, &c);

    int mn = min(a, min(b, c));

    if(n == 1) return printf("0\n"), 0;
    if(n == 2) return printf("%d\n", min(a, b)), 0;
    if(mn == a || mn == b) printf("%d\n", mn * (n-1));
    else printf("%d\n", min(a, b) + mn*(n-2));


    return 0;
}
