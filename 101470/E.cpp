#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

void file(){
    freopen("e.in", "r", stdin);
}

typedef long long ll;

const int N = 1000006;

pair<long long, long long> p[N];

/*ll D(int i, int j, int k){
    return (p[i].ff * p[j].ss + p[i].ss * p[k].ff + p[j].ff * p[j].ss)
    -(p[k].ff * p[j].ss + p[k].ss * p[i].ff + p[j].ff * p[i].ss);
}*/

ll D(int i, int j, int k){
    return (p[i].ff * p[j].ss + p[i].ss * p[k].ff + p[j].ff * p[k].ss)
    -(p[k].ff * p[j].ss + p[k].ss * p[i].ff + p[j].ff * p[i].ss);
}


int n;
vector<int> f(){
    sort(p, p+n);

    vector<int> L, U;

    for(int i = 0; i < n; i++){
        while (L.size() >= 2 and D(L[L.size() - 2], L[L.size() -1], i) < 0)
            L.pop_back();
        L.push_back(i);
    }

    for(int i = n-1; i >= 0; i--){
        while (U.size() >= 2 and D(U[U.size() - 2], U[U.size() -1], i) < 0)
            U.pop_back();

        U.push_back(i);
    }

    L.pop_back();
    U.pop_back();

    L.reserve(L.size() + U.size());
    L.insert(L.end(), U.begin(), U.end()); 

    return L;
}

int main(){
    file();

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%lld %lld", &p[i].ff, &p[i].ss);

    {
        set<pair<ll, ll> > ss;
        for(int i = 0; i < n; i++)
            ss.insert(p[i]);
        n = 0;
        for(pair<ll, ll> x : ss)
            p[n++] = x;
    }

    vector<int> v = f();

    double r2 = sqrt(2);
    double ans = 4*r2;
    for(int i = 0; i < v.size(); i++){
        ll dx = abs(p[ v[i] ].ff - p[ v[(i+1)%v.size() ] ].ff);
        ll dy = abs(p[ v[i] ].ss - p[ v[(i+1)%v.size() ] ].ss);
        ans += min(dx, dy)*r2 + abs(dx - dy);
    }

    printf("%.20lf\n", (double)ans);

    return 0;
}
