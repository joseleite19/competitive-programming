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
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define debug(x) cerr << #x << " = " << x << endl

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 51;

int lo[N], hi[N];
int cnt[N];

int main(){
    clock_t tmp = clock();
    int n, q;

    scanf("%d %d", &n, &q);

    for1(i, n) lo[i] = 1, hi[i] = n;

    while(q--){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a == 1) fore(i, b, c) lo[i] = max(lo[i], d);
        else fore(i, b, c) hi[i] = min(hi[i], d);
    }

    for1(i, n) if(lo[i] > hi[i])
        return printf("-1\n"), 0;

    int ans = 50*50+1;

    srand(time(0));
    while(double(clock() - tmp)/CLOCKS_PER_SEC < 2.8){
        memset(cnt, 0, sizeof cnt);
        for1(i, n){
            cnt[ rand() % (hi[i] - lo[i] + 1) + lo[i] ]++;
        }
        q = 0;
        for1(i, n)
            q += cnt[i] * cnt[i];
        ans = min(ans, q);
    }

    printf("%d\n", ans);


    return 0;
}
