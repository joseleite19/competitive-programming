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
const int N = 100005;
int n, c[N];

bool dfs(int u, int bit){
    vector<int> v;
    forn(i, n) if((1 << i) & bit)
        v.pb(i);
    int k = v.size();

    int sum;
    forn(i, 1 << k){
        sum = 1;
        forn(j, k) if(i ,,
    }
}

int main(){

    scanf("%d", &n);

    if(n == 1) return printf("YES\n"), 0;

    forn(i, n) scanf("%d", c+i);

    int cnt = 0;
    forn(i, n){
        cnt += c[i] == n;
        if(c[i] == 2) return printf("NO\n"), 0;
    }

    if(cnt != 1) return printf("NO\n"), 0;

    forn(i, n) if(c[i] == n){
        if(!dfs(i, (1 << n) - (1 << i)))
            return printf("NO\n"), 0;
    }

    printf("YES\n");



    return 0;
}
