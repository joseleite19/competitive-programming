#include <bits/stdc++.h>

using namespace std;

int n, m, l[222], v[222];


int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++) scanf("%d", l+i);

    for(int i = 0; i+1 < m; i++){
        int tmp = (l[i+1] - l[i]);

        if(tmp <= 0){
            tmp += n;
        }
        
        if(v[ l[i] ] && v[ l[i] ] != tmp) return printf("-1\n"), 0;
        v[ l[i] ] = tmp;
    }

    set<int> s;
    for(int i = 1; i <= n; i++) s.insert(i);

    for(int i = 1; i <= n; i++) if(v[i]){
        if(!s.count(v[i])) return printf("-1\n"), 0;
        s.erase(v[i]);
    }

    for(int i = 1; i <= n; i++) if(!v[i]){
        v[i] = *s.begin(); s.erase(s.begin());
    }

    for(int i = 1; i <= n; i++) printf("%d ", v[i]);
    printf("\n");
    

    return 0;
}
