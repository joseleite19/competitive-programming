#include <bits/stdc++.h>

using namespace std;

int n, p, cnt[55];
double fat[100];

long double dp[100][100][100];
int mark[100][100][100];

long double f(int i, int spaces, int sum){
    if(sum > p){
        return fat[n-spaces] * fat[spaces-1] * (spaces-1);
    }
    if(sum ==p){
        return fat[n-spaces] * fat[spaces] * spaces;
    }
    if(i == 51) return 0;
    long double &ans = dp[i][spaces][sum];
    if(mark[i][spaces][sum]) return ans;
    mark[i][spaces][sum] = 1;
    ans = 0;
    for(int q = 0; q <= cnt[i]; q++){
        ans += f(i+1, spaces + q, sum + q*i);
    }
    return ans;
}

int main(){
    fat[0] = 1;
    for(int i = 1; i < 100; i++)
        fat[i] = i*fat[i-1];

    scanf("%d", &n);

    int tmp = 0;
    for(int i = 0; i < n; i++){
        int x;
        scanf("%d", &x);
        cnt[x]++;
        tmp += x;
    }

    scanf("%d", &p);

    printf("%.20lf\n", (double)f(0, 0, 0) / fat[n]);


}
