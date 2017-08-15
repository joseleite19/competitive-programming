#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
long long v[1005];

int main(){

    long long k;
    
    scanf("%d %lld", &n, &k);

    for(int i = 0; i < n; i++)
        scanf("%lld", v+i);

    priority_queue<long long, vector<long long>, greater<long long> > pq;
    for(int i = 0; i < n; i++) pq.push(v[i]);

    int ans = 0;

    while(!pq.empty()){
        long long nt = pq.top(); pq.pop();
        while(k < (nt+1)/2){
            ans++;
            k <<= 1;
        }
        k = max(k, nt);
    }

    printf("%d\n", ans);


    return 0;
}
