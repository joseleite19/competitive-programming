#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 2*300005;

pair<pair<int, int>, long long> q[N];
long long p[N];
int o[N];
int n, m, k;
int ans[N];

vector<int> pos[N];

class Bit{
    int n, ptr;
    vector<long long> ft;

    void update(int x, long long v){
        for(; x <= n; x += x&-x)
            ft[x] += v;
    }
public:
    Bit(int sz) : n(sz), ptr(0), ft(sz+1, 0) {}

    long long query(int x) const{
        long long ans = 0;
        for(; x; x -= x&-x)
            ans += ft[x];
        return ans;
    }

    void update(int i, int j, long long v){
        if(i <= j){
            update(i, v);
            update(j+1, -v);
        }
        else{
            update(i, n, v);
            update(1, j, v);
        }
    }

    void to(int t){
        while(ptr < t){
            ptr++;
            update(q[ptr].ff.ff, q[ptr].ff.ss, q[ptr].ss);
        }
        while(ptr > t){
            update(q[ptr].ff.ff, q[ptr].ff.ss,-q[ptr].ss);
            ptr--;
        }
    }
};

void solve(int lo, int hi, vector<int> & povo, Bit &ft){
    if(povo.empty()) return;
    if(lo == hi){
        ft.to(lo);
        for(size_t i = 0; i < povo.size(); i++){
            int state = povo[i];
            long long sum = 0;
            for(size_t j = 0; j < pos[state].size(); j++){
                int position = pos[state][j];
                sum += ft.query(position);
                if(sum >= p[state]) break;
            }
            if(sum >= p[state]) ans[state] = lo;
        }
        return;
    }

    vector<int> l, r;
    int mid = (lo + hi) / 2;

    ft.to(mid);

    for(size_t i = 0; i < povo.size(); i++){
        int state = povo[i];
        long long sum = 0;
        for(size_t j = 0; j < pos[state].size(); j++){
            int position = pos[state][j];
            sum += ft.query(position);
            if(sum >= p[state]) break;
        }
        if(sum >= p[state]) l.push_back(state);
        else r.push_back(state);
    }

    solve(lo, mid, l, ft);
    solve(mid+1, hi, r, ft);
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= m; i++){
        scanf("%d", o+i);
        pos[ o[i] ].push_back(i);
    }
    
    for(int i = 1; i <= n; i++)
        scanf("%lld", p+i);
    
    scanf("%d", &k);

    for(int i = 1; i <= k; i++)
        scanf("%d %d %lld", &q[i].ff.ff, &q[i].ff.ss, &q[i].ss);

    Bit ft(m);

    vector<int> povo;
    for(int i = 1; i <= n; i++) povo.push_back(i);

    memset(ans, -1, sizeof ans);

    solve(1, k, povo, ft);

    for(int i = 1; i <= n; i++)
        if(ans[i] == -1) printf("NIE\n");
        else printf("%d\n", ans[i]);

    return 0;
}
