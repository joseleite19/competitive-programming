#include <bits/stdc++.h>

using namespace std;

const int N = 1000006;

char s[N];
int z[N];
int n;

void zfunc(){
    int L = 0, R = 0;
    memset(z, 0, (n+2) * sizeof(int));
    for(int i = 1; i < n; i++) {
        if(i <= R) z[i] = min(z[i - L], R - i + 1);
        while(z[i] + i < n && s[z[i] + i] == s[z[i]]) z[i]++;
        if(R < i + z[i] - 1) L = i, R = i + z[i] - 1;
    }
}

int period(){

    for(int i = 1; i < n; i++)
        if(i + z[i] == n && n % i == 0)
            return i;
    return n;
}

int main(){

    while(scanf("%[^\n]", s) != EOF && s[0] != '.'){
        getchar();
        n = strlen(s);
        assert(n);
        if(!n){
            printf("1\n"); continue;
        }
        zfunc();
        printf("%d\n", n / period());
        s[0] = 0;
    }

    return 0;
}
