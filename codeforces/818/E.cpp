#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int d, n, m;

const int N = 100005;

int x1[N], x2[N], yy1[N], y2[N];
int r[N], l[N], u[N], dd[N];

int sum[N];

void dol(){
    memset(sum, 0, sizeof sum);
    
    for(int i = 0; i < d; i++)
        sum[ min(x1[i], x2[i]) ]++;

    for(int i = 1; i < N; i++)
        sum[i] += sum[i-1];

    for(int i = 0; i < d; i++){
        l[i] = sum[min(x1[i], x2[i])]-1;
    }
}
void dod(){
    memset(sum, 0, sizeof sum);
    
    for(int i = 0; i < d; i++)
        sum[ min(yy1[i], y2[i]) ]++;

    for(int i = 1; i < N; i++)
        sum[i] += sum[i-1];


    for(int i = 0; i < d; i++){
        u[i] = sum[min(yy1[i], y2[i])]-1;
    }
}

void dor(){
    memset(sum, 0, sizeof sum);
    
    for(int i = 0; i < d; i++)
        sum[ max(x1[i], x2[i]) ]++;

    for(int i = N-2; i >= 0; i--)
        sum[i] += sum[i+1];

    for(int i = 0; i < d; i++){
        r[i] = sum[max(x1[i], x2[i])]-1;
    }
}

void dou(){
    memset(sum, 0, sizeof sum);
    
    for(int i = 0; i < d; i++)
        sum[ max(yy1[i], y2[i]) ]++;

    for(int i = N-2; i >= 0; i--)
        sum[i] += sum[i+1];

    for(int i = 0; i < d; i++){
        dd[i] = sum[max(yy1[i], y2[i])]-1;
    }
}


int main(){

    scanf("%d %d %d", &d, &n, &m);

    for(int i = 0; i < d; i++)
        scanf("%d %d %d %d", x1+i, yy1+i, x2+i, y2+i);

    int c[4];
    for(int i = 0; i < 4; i++) scanf("%d", c+i);

    dol(); dor(); dou(); dod();

    for(int i = 0; i < n; i++)
        if(c[0] == l[i] && c[1] == r[i] && c[2] == u[i] && c[3] == dd[i])
            return printf("%d\n", i+1), 0;

    printf("-1\n");


    return 0;
}
