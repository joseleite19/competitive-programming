#include <bits/stdc++.h>

using namespace std;

long long n;

vector<long long> v;

int main(){

    scanf("%lld", &n);

    for(long long i = 1; i < 1e18; i *= 3)
        v.push_back(i);

    long long ans = 0;

    while(n && !v.empty()){
        if(n % v.back() == 0){
            //ans += n / v.back() - 1;
            //n = v.back();
            n = 0;
            ans++;
        }
        else{
            ans += n / v.back();
            n %= v.back();
        }
        v.pop_back();
    }
    if(n) ans++;


    printf("%lld\n", ans);




    return 0;
}
