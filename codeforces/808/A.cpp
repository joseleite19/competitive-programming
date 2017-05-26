#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, ans = 0;

    scanf("%lld", &n);

    ans = 100000000000000;

    for(long long i = 1; i < 10000000000; i *= 10){
        for(long long j = i, k = 0; k < 10; j += i, k++)
            if(j > n)
                ans = min(ans, j - n);
    }



    printf("%lld\n", ans);



    return 0;
}
