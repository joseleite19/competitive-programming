#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back

using namespace std;

const int N = 200005;

char st[N][50];

pair<int, int> ori[N];

int indice[N];

vector<int> hqsort(int s, vector<int> v){

    if(v.empty()) return v;

    if(s == 0) return v;

    vector<int> ans[4];

    int mid = s/2;
    for(int x : v){
        if(ori[x].ff <= mid && ori[x].ss <= mid) ans[0].pb(x), swap(ori[x].ff, ori[x].ss);
        else if(ori[x].ff <= mid && ori[x].ss  > mid) ans[1].pb(x), ori[x].ss -= s - mid;
        else if(ori[x].ff  > mid && ori[x].ss >= mid) ans[2].pb(x), ori[x].ff -= s - mid, ori[x].ss -= s - mid;
        else if(ori[x].ff  > mid && ori[x].ss  < mid) ans[3].pb(x), ori[x].ff = s - ori[x].ff, ori[x].ss = mid - ori[x].ss, swap(ori[x].ff, ori[x].ss);;
    }

    for(int i = 0; i < 4; i++) ans[i] = hqsort(mid, ans[i]);

    for(int i = 1; i < 4; i++){
        for(int x : ans[i])
            ans[0].pb(x);
        ans[i].clear();
    }
    return ans[0];
}


int main(){

    int n, s;
    scanf("%d %d", &n, &s);

    for(int i = 0; i < n; i++)
        scanf("%d %d %s", &ori[i].ff, &ori[i].ss, st[i]);

    vector<int> v; for(int i = 0; i < n; i++) v.pb(i);

    v = hqsort(s, v);

    for(int i = 0; i < n; i++)
        printf("%s\n", st[ v[i] ]);

    return 0;
}
