#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
long long w, v[200005];

long long ans[200005];

int main(){

    scanf("%d %lld", &n, &w);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    long long sum = 0;
    
    priority_queue<pair<int,int> > q;
    for(int i = 0; i < n; i++){
        ans[i] = (v[i]+1)/2;
        q.push(mp(v[i], i));
        w -= ans[i];
    }

    if(w < 0) return printf("-1\n"), 0;

    while(!q.empty()){
        int i = q.top().ss; q.pop();
        if(!w) continue;
        long long tmp = min(v[i] - ans[i], w);
        ans[i] += tmp;
        w -= tmp;
    }

    if(w) return printf("-1\n"), 0;

    for(int i = 0; i < n; i++)
        printf("%lld ", ans[i]);
    printf("\n");

    return 0;
}
