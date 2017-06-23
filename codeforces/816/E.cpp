#include <bits/stdc++.h>

#define oo 1000000000000000000
using namespace std;

const int N = 5003;

int mark[N], n;
long long c[N], d[N], b;

vector<int> pai[N];


int main(){

    scanf("%d %lld", &n, &b);

    for(int i = 0; i < n; i++){
        scanf("%lld %lld", c+i, d+i);
        if(i){
            int x;
            scanf("%d", &x); x--;
            for(int q : pai[x]) pai[i].push_back(q);
        }
    }

    int ans = 0;
    while(1){
        long long mnc = oo, id = -1, qnt = 0, t = 0;

        for(int i = 0; i < n; i++){
            if(mark[i]) continue;
            long long w = c[i];
            long long sum = c[i] - d[i];
            int q = 1;
            for(int x : pai[i]) if(!mark[x]){
                sum += c[x] - d[x];
                q++;
            }
            if(sum <= b){
                if(q > qnt || (q == qnt && sum < mnc))
                    mnc = sum, qnt = q, id = i, t = 1;
            }
            if(qnt == 0 && w <= b && w < mnc) mnc = w, qnt = 1, id = i;
        }

        if(qnt == 0) break;

        ans += qnt;
        b -= mnc;
        mark[id] = 1;
        if(t == 1){
            for(int x : pai[id]) mark[x] = 1;
        }
    }

    printf("%d\n", ans);





}
