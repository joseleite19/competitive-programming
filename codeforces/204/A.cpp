#include <bits/stdc++.h>

using namespace std;

long long p(long long a, long long b){
    long long ret = 1;
    while(b--) ret *= a;
    return ret;
}

vector<long long> vet;

/*long long f(int i, ){
    if(i == vet.size()) return 1;
    long long ret = 0;

    int l, r;

    for(int d = l; d <= r; d++){

    }

    return ret;
}*/



long long f(long long x){
    if(x < 10) return x;
    int sz = 0;
    vet.clear();
    {
        long long v = x;
        while(v){
            vet.push_back(v % 10); sz++; v /= 10;
        }
    }

    long long ret = 9;

    for(int i = 2; i < sz; i++){
        ret += 9*p(10, i-2);
    }

    ret += (vet.back() - 1) * p(10, sz-2);
    ret += (x - vet.back()*p(10, sz-1))/10;
    if(vet[0] >= vet.back()){
        ret++;
    }
    vet.clear();

    return ret;
}

int main(){

    long long l, r;

    scanf("%lld %lld", &l, &r);

    printf("%lld\n", f(r) - f(l-1));

    return 0;
}
