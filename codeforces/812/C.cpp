#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 100005;

long long v[N], s;
int n;

long long f(long long mid){
    priority_queue<long long, vector<long long>, greater<long long> > q;

    for(int i = 1; i <= n; i++)
        q.push(v[i] + i*mid);

    long long ans = 0;
    while(mid--) ans += q.top(), q.pop();
    return ans;
}


int main(){

    scanf("%d %lld", &n, &s);

    for(int i = 1; i <= n; i++)
        scanf("%lld", v+i);

    int lo = 0, hi = n;

    while(lo + 1 < hi){
        int mid = (lo + hi) / 2;
        if(f(mid) <= s) lo = mid;
        else hi = mid - 1;
    }
    if(f(hi) > s) hi--;

    printf("%d %lld\n", hi, f(hi));



    return 0;
}
