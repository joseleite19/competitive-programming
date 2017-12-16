#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 300005;

int v[N];
int ans[N];

int main(){

    int n, k;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    priority_queue<pair<int, int> > q;
    for(int i = 0; i < k; i++)
        q.ep(v[i], i);

    ll tot = 0;
    int nx = k+1;
    for(int i = k; i < n+k; i++){
        if(i < n) q.ep(v[i], i);
        tot += 1LL*(i - q.top().ss)*q.top().ff;
        ans[q.top().ss] = nx++; q.pop();
    }

    printf("%lld\n", tot);
    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");

    return 0;
}
