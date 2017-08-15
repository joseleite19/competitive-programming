#include <bits/stdc++.h>

using namespace std;

bool sq(long long x){
    long long a = sqrt(x);
    for(long long q = a - 2; q <= a + 2; q++)
        if(q * q == x) return true;
    return false;
}

int main(){
    long long x;

    scanf("%lld", &x);

    bool ans = false;
    for(long long a = 0; a <= 1000; a++){
        for(long long b = 0; b <= 1000; b++){
            long long tmp = x - a*a - b*b;
            if(tmp < 0) continue;
            if(sq(tmp)){
                ans = true;
                break;
            }
        }
    }


    printf("%s\n", ans ? "YES" : "NO");
}
