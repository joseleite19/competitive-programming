#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cassert>

int o, d, k, banned[105], distancia[100005];

bool canInsert(int n){
    if(n > 0 && n <= 100000 && distancia[n] == -1)
        return !std::binary_search(banned, banned + k, n);
    return false;
}

int main(){

    while(scanf("%d %d %d", &o, &d, &k) == 3 && o + d + k){
        for(int i = 0; i < k; i++)
            scanf("%d", banned + i);

        std::sort(banned, banned+k);

        memset(distancia, -1, sizeof distancia);
        std::queue<int> q;

        q.push(o);
        distancia[o] = 0;
        while(!q.empty()){
            int channel = q.front(); q.pop();

            if(canInsert(channel+1)){
                distancia[channel+1] = distancia[channel]+1;
                q.push(channel+1);
            }
            if(canInsert(channel-1)){
                distancia[channel-1] = distancia[channel]+1;
                q.push(channel-1);
            }
            if(canInsert(2*channel)){
                distancia[2*channel] = distancia[channel]+1;
                q.push(2*channel);
            }
            if(canInsert(3*channel)){
                distancia[3*channel] = distancia[channel]+1;
                q.push(3*channel);
            }
            if(channel % 2 == 0 && canInsert(channel/2)){
                distancia[channel/2] = distancia[channel]+1;
                q.push(channel/2);
            }
        }
        if(d > 100000) printf("-1\n");
        else printf("%d\n", distancia[d]);
    }
}