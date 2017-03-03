#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    
    int tc = 1;
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        vector<ll> all;
        for (int i = 0; i < n; i++) {
            vector<ll> day(m);
            for (int j = 0; j < m; j++) scanf("%lld", &day[j]);
            sort(day.begin(), day.end());
            for (ll j = 0; j < m; j++) {
                day[j] += 2*(j+1) - 1;
                all.push_back(day[j]);
            }
        }
        
        sort(all.begin(), all.end());
        
        ll ans = 0;
        for (int i = 0; i < n; i++) ans += all[i];
        printf("Case #%d: %lld\n", tc++, ans);
    }
    
    return 0;
}

// 1 4 9 16 25 36 49 64
// 1 3 5 7 9 11 13 15