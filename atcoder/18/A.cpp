#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

int n;
int v[100005], k;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    sort(v, v+n);

    if(k > v[n-1]) return printf("IMPOSSIBLE\n"), 0;

    int g = 0;

    for(int i = 0; i < n; i++)
        g = gcd(g, v[i]);

    printf("%s\n", k % g == 0 ? "POSSIBLE" : "IMPOSSIBLE");


    return 0;
}
