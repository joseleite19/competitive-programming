#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, m;
int v[N], a[N];

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    set<int> pos;
    for(int i = 0; i <= n; i++) pos.insert(i);

    scanf("%d", &m);

    int t, p, x;
    while(m--){
        scanf("%d %d", &t, &p); p--;
        if(t == 1){
            scanf("%d", &x);
            for(p = *pos.lower_bound(p); x && p < n; p = *pos.lower_bound(p+1)){
                int tmp = min(a[p] - v[p], x);
                v[p] += tmp;
                x -= tmp;
                if(v[p] == a[p]) pos.erase(p);
            }
        }
        else if(t == 2) printf("%d\n", v[p]);
    }

    return 0;
}
