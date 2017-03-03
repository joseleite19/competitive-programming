#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, p[200005], b[200005], in[200005];
vector<int> v;
int vis[200005];

int can;

int dfs(int u){
	vis[u] = 1;

	if(vis[ p[u] ] == 1 && can) v.push_back(u);
	else if(vis[ p[u] ] == 0) dfs(p[u]);

	vis[u] = 2;
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", p+i);
		p[i]--;
	}

	for(int i = 0; i < n; i++)
		scanf("%d", b+i);

	int ans = 0;

	bool allzero = true;
	bool allone = true;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += b[i];
		if(b[i]) allzero = false;
		else allone = false;
	}

	if(cnt % 2 == 0) ans++;

	for(int i = 0; i < n; i++)
		in[ p[i] ]++;

	int flag = 0;
	for(int i = 0; i < n; i++)
		if(in[i] == 0 && vis[i] == 0){
			dfs(i);
			ans++;
			flag = true;
		}

	int cnt2 = 0;
	for(int i = 0; i < n; i++)
		if(vis[i] == 0){
			dfs(i);
			cnt2++;
		}

	if(cnt2 == 1){
		if(flag == true) ans++;
	}
	else ans += cnt2;

	printf("%d\n", ans);

	return 0;
}