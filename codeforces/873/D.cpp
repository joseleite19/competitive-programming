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

int n, k;
int l;
int v[N];

void f(int L, int R){
    if(R - L == 1){ v[L] = l--; return; }
    if(k == 0){
        for(int i = R-1; i >= L; i--)
            v[i] = l--;
        return;
    }
    k -= 2;
    int mid = (L+R)/2;
    f(L, mid);
    f(mid, R);
}

int main(){

    scanf("%d %d", &n, &k);

    l = n;
    k--;
    f(0, n);

    if(k) return printf("-1\n"), 0;

    forn(i, n) printf("%d ", v[i]); printf("\n");


    return 0;
}
