#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 100005;
const int B = 317;

int n, m, v[N];

int ans[N], atual;
pair<pair<int, int>, int> q[N]; //<<l, r>, id>

int cnt[N];

void add(int x){
    if(v[x] >= N) return;
    if(cnt[ v[x] ] == v[x]) atual--;
    cnt[ v[x] ]++;
    if(cnt[ v[x] ] == v[x]) atual++;
}

void rem(int x){
    if(v[x] >= N) return;
    if(cnt[ v[x] ] == v[x]) atual--;
    cnt[ v[x] ]--;
    if(cnt[ v[x] ] == v[x]) atual++;
}

int main(){

    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++)
        scanf("%d", v+i);

    for(int i = 0; i < m; i++)
        scanf("%d %d", &q[i].ff.ff, &q[i].ff.ss), q[i].ss = i, q[i].ff.ff--, q[i].ff.ss--;

    sort(q, q+m, [=](const pair<pair<int, int>, int> a, const pair<pair<int, int>, int> b){
        if(a.ff.ff / B != b.ff.ff / B) return a.ff.ff / B < b.ff.ff / B;
        return a.ff.ss < b.ff.ss;
    });

    int L = 0, R = -1;

    for(int i = 0; i < m; i++){
        int x = q[i].ff.ff, y = q[i].ff.ss, id = q[i].ss;
        while(R < y) add(++R);
        while(L > x) add(--L);
        while(R > y) rem(R--);
        while(L < x) rem(L++);
        ans[id] = atual;
    }

    for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);



}
