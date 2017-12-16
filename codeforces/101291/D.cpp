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

int v[N];
int n, r;

int main(){

    int x, k;

    scanf("%d %d %d", &n, &k, &r);

    forn(i, k){
        scanf("%d", &x);
        v[x]++;
    }

    int cnt = 0;

    for1(i, r) cnt += v[i];

    int ans = 0;
    if(cnt == 0) v[r] = v[r-1] = 1, cnt = 2, ans += 2;
    if(cnt == 1){
        if(v[r]) v[r-1] = 1;
        else v[r] = 1;
        ans++;
        cnt = 2;
    }

    fore(i, r+1, n){
        cnt -= v[i-r];
        cnt += v[i];
        if(cnt == 0) v[i] = 1, cnt++, ans++;
        if(cnt == 1){
            if(v[i]) v[i-1] = 1;
            else v[i] = 1;
            cnt++;
            ans++;
        }
    }

    printf("%d\n", ans);


    return 0;
}
