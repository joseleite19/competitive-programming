#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int cnt[20*N], t[20*N][2], v[N];
int n, p = 1;

int LG = 20;

void add(int x){
    cnt[0]++;
    int ptr = 0;
    for(int w = LG; w >= 0; w--){
        int c = (x >> w) & 1;
        if(!t[ptr][c]) t[ptr][c] = p++;
        ptr = t[ptr][c];
        cnt[ptr]++;
    }
}

int qry(int x){

    int ptr = 0;
    int ans = 0;
    for(int w = LG; w >= 0; w--){
        int c = (x >> w) & 1;
        if(!t[ptr][c]){

            break;
        }
        //printf("%d %d %d\n", w, ptr, cnt[ t[ptr][c] ]);
        if(cnt[ t[ptr][c] ] < (1 << w)){
            ptr = t[ptr][c];
        }
        else{
            ans |= (1 << w);
            if(!t[ptr][1^c]) break;
            ptr = t[ptr][1^c];
        }
    }
    return ans;
}

int main(){

    int m;
    scanf("%d %d", &n, &m);

    set<int> vis;
    for(int i = 0; i < n; i++){
        scanf("%d", v+i);
        if(vis.count(v[i])) continue;
        add(v[i]);
        vis.insert(v[i]);
    }


    int x = 0, tmp;
    while(m--){
        scanf("%d", &tmp);
        x ^= tmp;

        printf("%d\n", qry(x));
    }

    return 0;
}
