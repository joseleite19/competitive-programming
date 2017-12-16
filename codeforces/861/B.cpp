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

int mark[N+1];

int main(){

    int n, m;

    scanf("%d %d", &n, &m);

    if(n == 1){
        printf("1\n");
        return 0;
    }
    if(m == 0){
        printf("-1\n");
        return 0;
    }

    forn(i, m){
        int a, b;
        scanf("%d %d", &a, &b);
        if(a == n) return printf("%d\n", b), 0;
        for1(i, N){
            if((a + i - 1) / i == b)
                mark[i]++;
        }
    }

    int ans = -1, cnt = 0;
    for1(i, N) if(mark[i] == m){
        ans = (n + i - 1) / i;
        cnt++;
    }
    if(cnt > 1) ans = -1;

    printf("%d\n", ans);


    return 0;
}
