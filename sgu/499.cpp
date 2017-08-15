#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define eb emplace_back

using namespace std;

const int N = 1000006;

int n, mark[N];

int main(){

    scanf("%d", &n);

    int ans = 1, x;
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        mark[x]++;
    }

    for(int i = 2; i < N; i++){
        x = 0;
        for(int j = i; j < N; j += i) x += mark[j];
        if(x >= 2) ans = i;
    }

    printf("%d\n", ans);

    return 0;
}
