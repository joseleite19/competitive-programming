#include <bits/stdc++.h>

int f(int x){
    if(x == 1) return 1;
    if(x & 1) return 1 + f(3*x + 1);
    return 1 + f(x / 2);
}

int main(){
    int x;

    scanf("%d", &x);

    printf("%d\n", f(x));
}
