#include <bits/stdc++.h>

using namespace std;

const int N = 1005;

vector<int> g[N];

int n;
long long x[N], y[N], r[N];

long long dist(int i, int j){
    return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
}

const double pi = acos(-1);
long long dp[N][2][2];
bool mark[N][2][2];


long long f(int i, int j, int k){

    if(mark[i][j][k]) return dp[i][j][k];

    long long ans = 0;

    long long t1 = 0, t2 = 0;
    
    for(int v : g[i]){
        t1 = t2 = r[v] * r[v];
        if(j) t1 = -t1;
        if(k) t2 = -t2;
        ans += max(t1 + f(v, j^1, k), t2 + f(v, j, k^1));
    }
    mark[i][j][k] = 1;
    return dp[i][j][k] = ans;
}


int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld %lld %lld", x+i, y+i, r+i);

    vector<int> start;
    for(int i = 0; i < n; i++){
        int k = -1;

        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(r[i] >= r[j]) continue;
            long long tmp = dist(i, j);
            if(tmp < r[j] * r[j]){
                if(k == -1 || r[j] < r[k])
                    k = j;
            }
        }

        if(k == -1) k = n;
        g[k].push_back(i);
    }


    printf("%.20lf\n", pi * f(n, 0, 0));

    return 0;
}
