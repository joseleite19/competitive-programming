#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 200005;
const int B = 448;

int n, t;
ll v[N], atual, ans[N], K[1000006];
pair<pii, int> q[N];

inline void add(int i){
    atual -= K[ v[i] ] * K[ v[i] ] * v[i];
    K[ v[i] ]++;
    atual += K[ v[i] ] * K[ v[i] ] * v[i];
}

inline void rem(int i){
    atual -= K[ v[i] ] * K[ v[i] ] * v[i];
    K[ v[i] ]--;
    atual += K[ v[i] ] * K[ v[i] ] * v[i];

}

int main(){
    
    scanf("%d %d", &n, &t);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    for(int i = 0; i < t; i++)
        scanf("%d %d", &q[i].ff.ff, &q[i].ff.ss), q[i].ss = i, q[i].ff.ff--, q[i].ff.ss--;
    
    sort(q, q+t, [=](const pair<pii, int>& a, const pair<pii, int>& b){
        if(a.ff.ff/B != b.ff.ff/B) return a.ff.ff/B < b.ff.ff/B;
        return a.ff.ss < b.ff.ss;
    });

    int L = 0, R = -1, x, y, id;

    for(int i = 0; i < t; i++){
        x = q[i].ff.ff, y = q[i].ff.ss, id = q[i].ss;
        while(R < y) add(++R);
        while(L > x) add(--L);
        while(R > y) rem(R--);
        while(L < x) rem(L++);
        ans[id] = atual;
    }

    for(int i = 0; i < t; i++)
        printf("%lld\n", ans[i]);

}
