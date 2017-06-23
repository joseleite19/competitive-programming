#include <bits/stdc++.h>

using namespace std;

const int N = 3000006;

int ptr = 1, tr[N][2], cnt[N];

void put(int p, int add){

    int pt = 0;
    for(int i = 30; i >= 0; i--){
        int c = 0;
        if(p & (1 << i)) c = 1;
        if(!tr[pt][c]) tr[pt][c] = ptr++;
        pt = tr[pt][c];
        cnt[pt] += add;
    }
}

int query(int p, int l){
    int ans = 0;
    int pt = 0;
    for(int i = 30; i >= 0; i--){
        int c = 0, q = 0;
        if(p & (1 << i)) c = 1;
        if(l & (1 << i)) q = 1;

        if(q){
            ans += cnt[ tr[pt][c] ];
            pt = tr[pt][1^c];
        }
        else{
            pt = tr[pt][c];
        }

        if(!pt) break;
    }

    return ans;
}

int main(){

    int q;

    int t, p, l;

    scanf("%d", &q);

    while(q--){
        scanf("%d %d", &t, &p);
        if(t == 1) put(p, 1);
        if(t == 2) put(p,-1);
        if(t == 3){
            scanf("%d", &l);
            printf("%d\n", query(p, l));
        }
    }


    return 0;
}
