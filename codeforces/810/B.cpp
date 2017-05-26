#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, f;
long long k[100005], l[100005];

int main(){

    scanf("%d %d", &n, &f);

    for(int i = 0; i < n; i++)
        scanf("%lld %lld", k+i, l+i);

    priority_queue<long long> q;

    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(l[i] >= k[i]) sum += k[i];
        else sum += l[i];
        l[i] -= k[i];
        
        q.push(max(0LL, min(k[i], l[i])));
    }

    while(f--){
        sum += q.top(), q.pop();
    }

    printf("%lld\n", sum);




	return 0;
}
