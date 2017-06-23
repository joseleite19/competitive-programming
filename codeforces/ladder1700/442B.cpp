#include <bits/stdc++.h>

using namespace std;

const int N = 102;

int n;
double p[N];

double dp[N][2];
int mark[N][2], pass = 1;

double f(int i, bool ja){
    if(i == n) return ja;
    if(mark[i][ja] == pass) return dp[i][ja];
    mark[i][ja] = pass;
    double tmp = 0;

    tmp = (1 - p[i]) * f(i+1, ja);
    if(!ja) tmp += p[i] * f(i+1, 1);

    double ans = tmp;
    return dp[i][ja] = ans;
}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lf", p+i);

    sort(p, p+n);

    double ans = 0;
    for(int i = n-1; i >= 0; i--)
        ans = max(ans, f(i, 0));

    printf("%.20lf\n", ans);


    return 0;
}
