#include <bits/stdc++.h>

using namespace std;

int main(){
    long long a, b;

    scanf("%lld %lld", &a, &b);

    long long k = 1;

    bool ans = 0;
    while(1){
        if(k & 1) a -= k;
        else b -= k;
        if(a < 0){ ans = 0; break; }
        if(b < 0){ ans = 1; break; }
        k++;
    }

    printf("%s\n", ans == 0 ? "Vladik" : "Valera");



    return 0;
}
