#include <bits/stdc++.h>

#define oo 1000000000000000000
using namespace std;

const int N = 5003;

int mark[N], n;
long long c[N], d[N], b;

vector<int> g[N];


int main(){

    scanf("%d %lld", &n, &b);

    for(int i = 0; i < n; i++){
        scanf("%lld %lld", c+i, d+i);
        if(i){
            int x;
            scanf("%d", &x); x--;
            g[x].push_back(i);
        }
    }

}
