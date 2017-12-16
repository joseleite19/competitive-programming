#include <bits/stdc++.h>

#define mt make_tuple
using namespace std;

const int N = 1003;

vector<tuple<int, int, int> > g[N];

int n, m;
double dt[N];
double f(double t){
    for(int i = 0; i < n; i++)
        dt[i] = 1e50;

    dt[0] = 0;
    priority_queue<tuple<double, int> > q;
    q.push(mt(0, 0));

            int v, a, b;
        int u; double w;
    while(!q.empty()){
        tie(w, u) = q.top(); q.pop();
        if(-w > dt[u]) continue;
        if(u == n-1) return dt[u];

        for(auto x : g[u]){
            tie(v, a, b) = x;
            double tmp = a * t + b + dt[u];
            if(tmp < dt[v]){
                dt[v] = tmp;
                q.push(mt(-dt[v], v));
            }
        }
    }
    return -1;
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d); a--, b--;
        g[a].emplace_back(b, c, d);
        g[b].emplace_back(a, c, d);
    }

    double lo = 0, hi = 24*60;

    for(int i = 0; i < 300; i++){
        double tmp = (hi - lo)/3;
        double m1 = lo + tmp;
        double m2 = hi - tmp;
        if(f(m1) > f(m2)) hi = m2;
        else lo = m1;
    }

    printf("%.5lf\n", f(lo));

}
