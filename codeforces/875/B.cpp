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
const int N = 500005;

int n;
int v[N], p[N];

int main(){

    scanf("%d", &n);

    for1(i, n) scanf("%d", p+i);

    printf("1");

    int R = n;
    int ans = 1;
    for1(i, n){
        v[ p[i] ] = 1;
        ans++;
        while(R >= 0 && v[R]) R--, ans--;
        printf(" %d", ans);
    }
    printf("\n");


    return 0;
}
