#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 400005;

int n, m, k, t;
int a[N], b[N];

int main(){

    scanf("%d %d %d %d", &n, &m, &k, &t);

    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    for(int i = 0; i < m; i++)
        scanf("%d", b+i);

    sort(a, a+n);
    sort(b, b+m);

    int ans = 0;

    int j = 0, w = 0;
    for(int i = 0; i < n; i++){
        while(j < m && b[j] < a[i] - t) j++, w = 0;
        if(j == m) break;
        if(abs(a[i] - b[j]) <= t){
            w++;
            ans++;
            if(w == k) j++, w = 0;
        }
    }

    printf("%d\n", ans);

    return 0;
}
