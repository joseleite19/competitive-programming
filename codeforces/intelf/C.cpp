#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long ans[100005];

int main(){

	int n, m, k;

	pair<int, int> v[100005];

	memset(ans, -1, sizeof ans);

	scanf("%d %d %d", &n, &m, &k);

	map<int, vector<int> > hack;
	map<int, vector<int> > hack2;
	for(int i = 1; i <= k; i++){
		scanf("%d %d", &v[i].ff, &v[i].ss);

		hack[v[i].ff - v[i].ss].push_back(i);
		hack2[v[i].ff + v[i].ss].push_back(i);
	}

	int x = 0, y = 0;
	long long t = 0;

	int go = 1; // 1 = up/ri; 2 = up/le; 3 = down/ri; 4; donw/le

	map<pair<int,int>, bool> vis;

	while(1){
		if(vis[mp(x,y)]) break;
		vis[mp(x,y)] = 1;

		assert(1 <= go && go <= 4);

		if(go == 1 || go == 4){
			for(int each : hack[x - y]){
				if(ans[each] == -1){
					int dist = min(abs(x - v[each].ff), abs(y - v[each].ss));
					ans[each] = t + dist;
				}
			}
			while((int)hack[x-y].size() > 0) hack[x-y].pop_back();
		}
		else{
			for(int each : hack2[x + y]){
				if(ans[each] == -1){
					int dist = min(abs(x - v[each].ff), abs(y - v[each].ss));
					ans[each] = t + dist;
				}
			}
			while((int)hack2[x+y].size() > 0) hack2[x+y].pop_back();
		}
		
		int dist;
		if(go == 1){
			dist = min(n - x, m - y);
			x += dist;
			y += dist;
		}
		else if(go == 2){
			dist = min(x, m - y);
			x -= dist;
			y += dist;

		}
		else if(go == 3){
			dist = min(n - x, y);
			x += dist;
			y -= dist;

		}
		else{
			dist = min(x, y);
			x -= dist;
			y -= dist;
		}

		if((x == n && y == m) || (x == n && y == 0) || (x == 0 && y == m) || (x == 0 && y == 0)) break;
		t += dist;

		if(x == n) go++;
		else if(y == m) go += 2;
		else if(x == 0) go--;
		else go -= 2;
	}

	for(int i = 1; i <= k; i++)
		printf("%lld\n", ans[i]);

	return 0;
}