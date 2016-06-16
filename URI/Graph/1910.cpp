#include <bits/stdc++.h>

using namespace std;

int o, d, k, banned[105], distancia[100005], fila[100005];

bool canInsert(int n){
    if(n > 0 && n <= 100000 && distancia[n] == -1){
        int i = lower_bound(banned, banned + k, n) - banned;
        if(i == k || banned[i] != n)
            return true;
    }
    return false;
}

int main(){

    while(scanf("%d %d %d", &o, &d, &k) == 3 && o + d + k){
        for(int i = 0; i < k; i++)
            scanf("%d", banned + i);
        sort(banned, banned+k);
        memset(distancia, -1, sizeof distancia);
        // queue<int> q;
        int front = 0;
        int back = 0;
        fila[back++] = o;
        // q.push(o);
        distancia[o] = 0;
        while(back > front){
            int channel = fila[front++];
            // if(channel < 10) printf("dasds %d\n", channel);
            if(canInsert(channel+1)){
                distancia[channel+1] = distancia[channel]+1;
                fila[back++] = channel+1;
            }
            if(canInsert(channel-1)){
                distancia[channel-1] = distancia[channel]+1;
                fila[back++] = channel-1;
            }
            if(canInsert(2*channel)){
                distancia[2*channel] = distancia[channel]+1;
                fila[back++] = 2*channel;
            }
            if(canInsert(3*channel)){
                distancia[3*channel] = distancia[channel]+1;
                fila[back++] = 3*channel;
            }
            if(channel % 2 == 0 && canInsert(channel/2)){
                distancia[channel/2] = distancia[channel]+1;
                fila[back++] = channel/2;
            }
        }
        printf("%d\n", distancia[d]);
    }
}