#include <bits/stdc++.h>

using namespace std;

int main(){
    int n = 100000, m = 99998;
    printf("%d %d 1\n", n, m);

    for(int i = 0; i < m; i++){
        printf("%d %d\n", i+1, i+2);
    }

    printf("1 %d\n", n);
}
