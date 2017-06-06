#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

const int N = 1004;

pair<double, pair<int, int> > e[N];
int p[N];

int f(int x){
    return x == p[x] ? x : p[x] = f(p[x]);
}

int main(){

    int q, c;
    double t;


    while(scanf("%d %d %lf", &q, &c, &t) == 3 && q+c){
        for(int i = 0; i <= q; i++) p[i] = i;

        for(int i = 0; i < c; i++)
            scanf("%d %d %lf", &e[i].ss.ff, &e[i].ss.ss, &e[i].ff);

        sort(e, e+c);

        double ans = 0;
        int cnt = 0;
        for(int i = 0; i < c; i++){
            if(f(e[i].ss.ff) != f(e[i].ss.ss)){
                p[ f(e[i].ss.ff) ] = f(e[i].ss.ss);
                ans += e[i].ff;
                if(e[i].ff > t)
                    cnt++, ans += 2;
            }
        }

        printf("%.2lf %d\n", ans, cnt);
    }


}
