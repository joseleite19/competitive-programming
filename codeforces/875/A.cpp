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
    int ans = x;
    while(x) ans += x % 10, x /= 10;
    return ans;
}

int main(){

    int n;

    scanf("%d", &n);

    set<int> ans;
    fore(i, max(0, n - 6000), n)
        if(f(i) == n)
            ans.insert(i);

    printf("%d\n", ans.size());

    for(int x : ans) printf("%d\n", x);



    return 0;
}
