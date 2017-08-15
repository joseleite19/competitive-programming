#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007
#define oo 1000000000000000000

using namespace std;

int n, k, v[100];

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    int sum = 0;
    sort(v, v+n); reverse(v, v+n);

    for(int i = 0; i < k; i++)
        sum += v[i];

    printf("%d\n", sum);




    return 0;
}
