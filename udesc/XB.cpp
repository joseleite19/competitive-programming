#include <bits/stdc++.h>

using namespace std;

int n;
double c[20][20], x[20], d;

double h(int i, int j){
    double lo = x[i], hi = 1e20;
    
    for(int k = 0; k < 100; k++){
        double mid = (lo + hi) / 2;
        if(hypot(mid - x[i], d - x[j] - x[i]) >= x[i] + x[j]) hi = mid;
        else lo = mid;
    }
    return lo - 2*x[i] + x[j];
}

double dp[1 << 20][20];
int mark[1 << 20][20], pass;

double f(int bit, int last){
    if(!bit) return 0;
    if(mark[bit][last] == pass) return dp[bit][last];
    mark[bit][last] = pass;

    double ans = 1e20;
    for(int i = 0; i < n; i++){
        if(bit & (1 << i)){
            ans = min(ans, c[last][i] + f(bit ^ (1 << i), i));
        }
    }
    return dp[bit][last] = ans;
}


int main(){

    while(scanf("%d %lf", &n, &d) == 2 && n){
        for(int i = 0; i < n; i++)
            scanf("%lf", x+i);

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(i != j)
                    c[i][j] = h(i, j);
        for(int j = 0; j < n; j++)
            c[17][j] = 2*x[j];

        pass++;
        printf("%d\n", int(round(f((1 << n)-1, 17))));
    }

    return 0;
}
