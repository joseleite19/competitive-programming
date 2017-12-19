#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 100005;

int main(){

	int t;

	scanf("%d", &t);

	while(t--){
		int n, k;
		set<pair<int, int> > s;

		scanf("%d %d", &n, &k);
		int id, h, w, l;
		forn(i, n){
			scanf("%d %d %d %d", &id, &h, &w, &l);
			s.emplace(h*w*l, -id);
			if(s.size() > k) s.erase(s.begin());
		}
		vector<int> ans;
		forn(i, k) ans.pb(-prev(s.end())->ss), s.erase(prev(s.end()));
		sort(ans.begin(), ans.end());
		printf("%d", ans[0]);
		fore(i, 1, k) printf(" %d", ans[i]);
		printf("\n");
	}

    return 0;
}
