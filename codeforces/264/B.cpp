#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int lp[N];

int n, v[N], cnt[N];

void comp(){
    lp[1] = 1;
    for(int i = 2; i < N; i += 2) lp[i] = 2;
    int i;
    for(i = 3; i*i < N; i += 2){
        if(!lp[i]){
            lp[i] = i;
            for(int j = i*i; j < N; j += i)
                lp[j] = i;
        }
    }
    
    for(; i < N; i++) if(!lp[i])
        lp[i] = i;

}


int main(){
    comp();

    scanf("%d", &n);

    if(n == 1) return printf("1\n"), 0;

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    int ans = 0;
    for(int i = 0; i < n; i++){
        set<int> s;
        while(v[i] > 1){
            s.insert(lp[ v[i] ]);
            v[i] /= lp[ v[i] ];
        }
        if(s.empty()) continue;

        int tmp = 0;
        for(int x : s) tmp = max(tmp, cnt[x]);
        tmp++;
        for(int x : s) cnt[x] = tmp;
        ans = max(ans, tmp);
    }

    printf("%d\n", ans);



    return 0;
}
