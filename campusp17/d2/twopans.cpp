#include <bits/stdc++.h>

#define MOD (1000000007)

using namespace std;

const int N = 100005;

int v[N], c[N];


int main(){

    int n;

    scanf("%d", &n);

    if(n == 1) return printf("2\n1A 0X\n1B 0X\n"), 0;

    memset(c, 'X', sizeof c);

    int ptr = 0;
    for(int i = 1; i <= n; i++){
        v[ptr] = i;
        c[ptr] = 'A';
        ptr++;
    }
    for(int i = 1; i <= n; i++){
        v[ptr] = i;
        c[ptr] = 'B';
        ptr++;
    }

    if(ptr & 1) ptr++;
    printf("%d\n", ptr/2);

    for(int i = 0; i < ptr; i += 2)
        printf("%d%c %d%c\n", v[i], c[i], v[i+1], c[i+1]);
    

    return 0;
}
