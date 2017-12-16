#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define mp make_pair
#define pb push_back
#define MOD 1000000007LL

using namespace std;
typedef long long ll;

const int N = 100005;

int x, v[N], n;

int main(){

    scanf("%d %d", &n, &x);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    for(int i = 0; i < n; i++)
        if(v[i] == x)
            return printf("1\n"), 0;

    int mn = 101, mx = -1;

    for(int i = 0; i < n; i++)
        mn = min(mn, v[i]), mx = max(mx, v[i]);

    if(mn <= x && x <= mx) printf("2\n");
    else printf("-1\n");


    return 0;
}
