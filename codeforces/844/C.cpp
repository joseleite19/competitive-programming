#include <bits/stdc++.h>

#define ff first
#define ss second
#define eb emplace_back
#define pb push_back

using namespace std;

const int N = 100005;

int p[N];

int f(int x){
    return x == p[x] ? x : p[x] = f(p[x]);
}

pair<int, int> v[N];

int main(){
    int n;

    scanf("%d", &n);

    for(int i = 0; i < N; i++)
        p[i] = i;

    for(int i = 0; i < n; i++)
        scanf("%d", &v[i].ff), v[i].ss = i;

    sort(v, v+n);

    for(int i = 0; i < n; i++){
        if(f(i) != f(v[i].ss))
            p[f(i)] = f(v[i].ss);
    }

    vector<vector<int> > v;

    set<int> s;

    for(int i = 0; i < n; i++)
        s.insert(f(i));

    map<int, int> go;
    int p = 0;
    for(int x : s){
        go[x] = p++;
    }

    v.resize(p);

    for(int i = 0; i < n; i++){
        v[go[ f(i) ]].push_back(i+1);
    }

    printf("%d\n", (int)v.size());

    for(vector<int> & x : v){
        printf("%d", (int)x.size());

        for(int q : x) printf(" %d", q);
        printf("\n");
    }


    return 0;
}
