#include <bits/stdc++.h>

using namespace std;

const int N = 60004;
int n;
long long x[N], v[N];

double f(double mid){ // chutando ponto mid
    double ans = 0;
    for(int i = 0; i < n; i++){
       ans = max(ans, fabs(x[i] - mid)/v[i]);
    }
    
    return ans;
}


int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld", x+i);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    double hi = 1e15, lo = 0;

    for(int k = 0; k < 200; k++){
        double tmp = (hi - lo) / 3;
        double mid1 = lo + tmp;
        double mid2 = hi - tmp;
        if(f(mid1) < f(mid2)) hi = mid2;
        else lo = mid1;
    }

    printf("%.20lf\n", f(lo));

    return 0;
}
