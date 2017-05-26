#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, k, v[200];

int f(int x, int n){
    if(x % n == 0) return x / n;
    int ret = x % n;
    if(ret < (n+1)/2) return x / n;
    return x / n + 1;
}

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    int sum = 0;

    for(int i = 0; i < n; i++)
        sum += v[i];

    int ans = 0, tmp = n;

    while(f(sum, tmp) != k)
        ans++, tmp++, sum += k;

    printf("%d\n", ans);




	return 0;
}
