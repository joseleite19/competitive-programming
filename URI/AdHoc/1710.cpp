#include <bits/stdc++.h>

#define pb push_back

using namespace std;

const int N = 10004;

int n, m;
int a[N], b[N], c[N], d[N];
int x[N], y[N], z[N];

int solve(const vector<int> &v, int j){
    if(j == m || v.size() <= 1) return v.size();

    vector<int> l, r;
    for(int i : v){
        if(a[j]*x[i] + b[j]*y[i] + c[j]*z[i] > d[j])
            l.pb(i);
        else r.pb(i);
    }
    return max(solve(l, j+1), solve(r, j+1));
}

int main(){

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++)
        scanf("%d %d %d %d", a+i, b+i, c+i, d+i);

    for(int i = 0; i < n; i++)
        scanf("%d %d %d", x+i, y+i, z+i);

    vector<int> tmp;
    for(int i = 0; i < n; i++)
        tmp.pb(i);

    printf("%d\n", solve(tmp, 0));

}
