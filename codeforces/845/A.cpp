#include <bits/stdc++.h>

using namespace std;

int n, v[20000];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < 2*n; i++)
        scanf("%d", v+i);

    sort(v, v+2*n);

    printf("%s\n", v[n-1] == v[n] ? "NO" : "YES");
    
}
