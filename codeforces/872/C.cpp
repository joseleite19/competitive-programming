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
    int ans = 0;
    if(x & 1) x -= 9, ans++;
    if(x < 0) return -1;
    if(x % 4 == 2) x -= 6, ans++;
    if(x < 0) return -1;
    if(x % 4) return -1;
    return ans + x / 4;
}

int main(){

    int q, x;

    scanf("%d", &q);

    while(q--){
        scanf("%d", &x);
        printf("%d\n", f(x));
    }



    return 0;
}
