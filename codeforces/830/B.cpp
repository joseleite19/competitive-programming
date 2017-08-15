#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000000007

using namespace std;

const int N = 100005;

int n;
set<int> s[N];

int ft[N];

void update(int x, int v){
    for(; x < N; x += x&-x)
        ft[x] += v;
}

int sum(int x){
    int ans = 0;
    for(; x > 0; x -= x&-x)
        ans += ft[x];
    return ans;
}

int query(int i, int j){
    return sum(j) - sum(i-1);
}

int main(){

    scanf("%d", &n);

    int x;
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        s[x].insert(i);
        update(i, 1);
    }

    int p = 0;
    long long ans = 0;
    for(int val = 1; val < N; val++){
        if(s[val].empty()) continue;
        set<int>::iterator it = s[val].lower_bound(p);

        if(it == s[val].begin()){
            it = s[val].end();
            it--;
            //printf("::%d %d %d\n", p, *it, query(p, *it));
            ans += query(p, *it);
            p = *it;
        }
        else{ 
            it--;
            //printf("|%d %d\n", p, n);
            //printf("!%d %d\n", 1,*it);
            ans += query(p, n)+ query(1, *it);
            p = *it;
        }
        for(int x : s[val]) update(x, -1);
        //printf("%d %d %lld %d\n", val, p, ans, n);
    }

    printf("%lld\n", ans);



    return 0;
}
