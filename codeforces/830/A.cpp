#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007

using namespace std;

const int N = 1003;

int a[N], v[2*N];

int main(){

    int n, k, p;

    scanf("%d %d %d", &n, &k, &p);

    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    for(int i = 0; i < k; i++)
        scanf("%d", v+i);

    int ans = 2*MOD;

    sort(a, a+n);
    sort(v, v+k);

    for(int i = n-1; i < k; i++){ // [i - (n-1), i]
        int d = 0;
        for(int j = 0; j < n; j++)
            d = max(d, abs(a[j] - v[i - (n-1)+j]) + abs(v[i - (n-1)+j] - p));
        ans = min(ans, d);
    }

    printf("%d\n", ans);

    return 0;
}
