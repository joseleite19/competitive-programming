#include <bits/stdc++.h>

using namespace std;

int n, k, a[200], b[200];

int main(){

    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%d", a+i);

    for(int i = 0; i < k; i++)
        scanf("%d", b+i);

    sort(b, b+k);
    reverse(b, b+k);

    int j = 0;

    for(int i = 0; i < n; i++){
        if(a[i]) continue;
        a[i] = b[j++];
    }

    printf("%s\n", is_sorted(a, a+n) ? "No" : "Yes");

    









    return 0;
}
