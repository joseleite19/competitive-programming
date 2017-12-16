#include <bits/stdc++.h>


int main(){
    int n, k;

    scanf("%d", &n);

    int a = 0, b = 0, tmp = 0;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        if(x & 1) a++, tmp ^= 1;
        else b++;
    }

    printf("%s\n", (tmp || a >= 2) ? "First" : "Second");


    return 0;
}
