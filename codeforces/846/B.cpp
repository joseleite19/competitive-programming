#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ep emplace
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;

int n, k;
ll m, v[N];

int cnt[N];

ll f(){
    priority_queue<int> q;
    for(int i = 0; i < k; i++){
        for(int j = cnt[i]; j < n; j++){
            q.push(v[i]);
        }
    }
    if(q.size() < k+1) return oo;
    while(q.size() > k+1) q.pop();
    ll ans = 0;
    while(!q.empty()) ans += q.top(), q.pop();
    return ans;
}

int main(){

    scanf("%d %d %lld", &n, &k, &m);

    for(int i = 0; i < k; i++)
        scanf("%lld", v+i);

    sort(v, v+k);

    ll tot = 0;

    for(int i = 0; i < k; i++)
        tot += v[i];

    ll ans = 0;
    while(tot >= m){
        bool can = true;
        for(int i = 0; i < k; i++) if(cnt[i] == n)
            can = false;
        if(!can) break;
        
        ll a = f();
        if(a == oo) break;
        if(tot < a){
            m -= tot;
            ans += k+1;
            for(int i = 0; i < k; i++)
                cnt[i]++;
        }
        else{
            priority_queue<int> q;

            for(int i = 0; i < k; i++)
                for(int j = cnt[i]; j < n; j++)
                    q.push(-v[i]);
            int tmp = 0;
            while(!q.empty() && tmp < k+1){
                tmp++;
                ans++;
                m += q.top(); q.pop();
            }
        }
    }

    priority_queue<int> q;

    for(int i = 0; i < k; i++)
        for(int j = cnt[i]; j < n; j++)
            q.push(-v[i]);

    while(!q.empty()){
        if(-q.top() > m) break;
        ans++;
        m += q.top(); q.pop();
    }

    printf("%lld\n", ans);






    return 0;
}
