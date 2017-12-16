#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int a[N], b[N], ida[N], idb[N];

int ans[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    for(int i = 0; i < n; i++)
        scanf("%d", b+i);

    for(int i = 0; i < n; i++)
        ida[i] = idb[i] = i;

    sort(ida, ida+n, [=](int q, int w){
        return a[q] > a[w];
    });
    
    sort(idb, idb+n, [=](int q, int w){
        return b[q] < b[w];
    });

    for(int i = 0; i < n; i++)
        ans[ idb[i] ] = a[ ida[i] ];

    for(int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");


    return 0;
}
