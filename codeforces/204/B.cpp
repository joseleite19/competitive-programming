#include <bits/stdc++.h>

#define oo 1000000000

using namespace std;

const int N = 100005;

int n, a[N], b[N];

int f(int x){
    int target = (n+1)/2;

    for(int i = 0; i < n; i++)
        if(a[i] == x)
            target--;
    if(target <= 0) return 0;
    int cnt = 0;
    for(int i = 0; i < n && target; i++){
        if(a[i] == x) continue;
        if(b[i] == x){
            cnt++;
            target--;
        }
    }
    return cnt;
}

int main(){

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d %d", a+i, b+i);

    map<int, int> m;

    for(int i = 0; i < n; i++){
        m[ a[i] ]++;
        if(b[i] != a[i]) m[ b[i] ]++;
    }

    vector<int> pos;

    for(pair<int, int> p : m)
        if(p.second >= (n+1)/2)
            pos.push_back(p.first);

    if(pos.empty()) return printf("-1\n"), 0;

    int ans = oo;

    for(int p : pos)
        ans = min(ans, f(p));

    printf("%d\n", ans);




    return 0;
}
