#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    static map<int, int> G[int(3e5) + 5];
    map<int, int> global;

    int n;
    scanf("%d", &n);

    vector<int> strengths(n + 5);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &strengths[i]);
        global[strengths[i]]++;
    }

    for (int i = 0; i < n-1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u][strengths[v]]++;
        G[v][strengths[u]]++;
    }

    int ans;
    if (n == 1) ans = strengths[1];
    else {
        ans = INT_MAX;
        for (int i = 1; i <= n; i++) {
            int me = strengths[i];
            int neighbor = G[i].rbegin()->first;

            global[me]--;
            global[neighbor]--;

            int other = INT_MIN;
            for (auto it = global.rbegin(); it != global.rend(); it++) {
                if (it->second > 0) {
                    if (global[it->first] + (it->first == neighbor) != G[i][it->first]) {
                        other = it->first;
                    }
                    break;
                }
            }

            ans = min(ans, max(me, max(neighbor + 1, other + 2)));

            global[me]++;
            global[neighbor]++;
        }
    }

    printf("%d\n", ans);

    return 0;
}