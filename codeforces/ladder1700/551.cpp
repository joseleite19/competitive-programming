#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

const int N = 100005;

int n, m;
long long v[N];


int main(){

    scanf("%d %d", &n, &m);

    for(int i = 1; i <= n; i++)
        scanf("%lld", v+i);

    multiset<pair<long long, int> > s;

    s.insert(mp(0, m));
    long long ans = 0, sum = 0;

    for(int i = 1; i <= n; i++){
        sum++;
        if(!v[i]) continue;
        int old = v[i];
        long long w = 0;
        while(!s.empty() && v[i]){
            pair<long long, int> q = *s.begin(); s.erase(s.begin());
            long long tmp = min(v[i], q.ss*1LL);
            w = max(w, q.ff + sum);
            v[i] -= tmp;
            q.ss -= tmp;
            if(q.ss) s.insert(q);
        }
        if(s.empty() && v[i]){
            w += (v[i] + m - 1) / m;

            int left = m;
            if(v[i] % m){
                left -= v[i] % m;
                s.insert(mp(v[i]/m, v[i] % m));
            }
            s.insert(mp((v[i] + m - 1) / m, left));

            v[i] = 0;
        }
        else{
            s.insert(mp(w-sum, old));
        }
        printf("%d %d\n", i, w);
        ans = max(ans, w);
    }

    printf("%lld\n", ans);





    return 0;
}
