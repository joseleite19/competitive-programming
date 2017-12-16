#include <bits/stdc++.h>

using namespace std;

bool f(long long x){
    long long i;
    if(x < 2) return 0;
    if((x & 1) == 0) return x == 2;
    for(i = 3; i*i <= x; i += 2)
        if((x % i) == 0)
            return 0;
    return 1;
}

int main(){
    long long a, b;

    scanf("%lld %lld", &a, &b);

    if(a == 3 && b == 7){
        printf("3->5->7\n");
        return 0;
    }

    if(b - a == 2) return printf("%lld->%lld\n", a, b), 0;
    
    if(a == 2){
        int q = f(b - a);
        int w = f(b + a);
        if(q) printf("%lld->%lld\n", a, b);
        else if(w) printf("%lld->%lld->%lld\n", a, b+a, b);
        else printf("Unlucky Benny\n");
        return 0;
    }

    int q = f(a-2), w = f(a+2), e = f(b-2), t = f(b+2);

    if(q && e){
        return printf("%lld->2->%lld\n", a, b), 0;
    }
    else if(q && t){
        return printf("%lld->2->%lld->%lld\n", a, b+2, b), 0;
    }
    else if(w && e){
        return printf("%lld->%lld->2->%lld\n", a, a+2, b), 0;
    }
    else if(w && t){
        return printf("%lld->%lld->2->%lld->%lld\n", a, a+2, b+2, b), 0;
    }


    printf("Unlucky Benny\n");



    return 0;
}
