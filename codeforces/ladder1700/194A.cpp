#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;
int n, v[502];

struct Bit{
    vector<long long> ft;
    int n;

    void update(int x, int v){
        for(; x <= n; x += x&-x)
            ft[x] += v;
    }

    void update(int i, int j, int v){
        update(i, v);
        update(j+1, -v);
    }

    long long query(int x){
        long long ans = 0;
        for(; x > 0; x -= x&-x)
            ans += ft[x];
        return ans;
    }

    long long query(int i, int j){
        return query(j) - query(i-1);
    }

    Bit(int size) : n(size), ft(size+1, 0LL) {}

};

int main(){
    int n, m, a, b[100005], p[100005];

    scanf("%d %d %d", &n, &m, &a);

    for(int i = 0; i < n; i++)
        scanf("%d", b+i);

    for(int i = 0; i < m; i++)
        scanf("%d", p+i);

    int r = 0;




    return 0;
}