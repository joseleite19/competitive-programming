#include <bits/stdc++.h>

using namespace std;

int n, k, v[200005];

int main(){
    long long ans = 0;

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    long long tmp = 0;
    for(int i = 0; i < k; i++) tmp += v[i];

    ans += tmp;
    for(int i = k; i < n; i++){
        tmp = tmp - v[i-k] + v[i];
        ans += tmp;
    }


    printf("%.20lf\n", (double)ans/(n-k+1));



    return 0;
}
