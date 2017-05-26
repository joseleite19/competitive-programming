#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
long long v[200005], sum[200005];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    sum[0] = v[0];
    for(int i = 0; i < n; i++)
        sum[i] = sum[i-1] + v[i];

    if(n == 1 || sum[n-1] & 1) return printf("NO\n"), 0;

    bool can = false;

    long long target = sum[n-1] / 2;
    for(int i = 0; i < n; i++){
        int id = lower_bound(sum, sum+n, target + v[i]) - sum;
        if(id != n && id > i && sum[id] == target + v[i]) can = true;
        id = lower_bound(sum, sum+n, target - v[i]) - sum;
        if(id != n && id < i && sum[id] == target - v[i]) can = true;
    }

    printf("%s\n", can ? "YES" : "NO");


    return 0;
}
