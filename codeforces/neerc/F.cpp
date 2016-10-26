#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("fragmentation.in", "r", stdin);
	freopen("fragmentation.out", "w", stdout);
}

int v[100005], qtd[100005], prox[100005], v2[100005];
bool vis[100005];
int vis2[100005];
vector<int> ans;

int main(){
	int i,n;

	// file();
	
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &v[i]);
		v2[i] = v[i];
		qtd[v[i]]++;
	}
	sort(v2,v2+n);
	for(i = 0; i < n-1; i++){
		if(v2[i] != v2[i+1])
			prox[v2[i]] = v2[i+1];
	}
	
	int vi = 0, l = 0;

	int niv = 1;

	for(int i = 0; i < 100005; i++) vis2[i] = 1e9;
	l = 1;
	int at = v[0];
	vis2[v[0]] = niv;
	qtd[v[0]]--;
	for(i = 1; i < n; i++){
		if (v[i] == at) {
			l++;
		} else {
			if (prox[at] == v[i] && !vis[at] && (!vi || (vis2[at] == niv && !qtd[at]))){
				l++;
				vi=1;
				vis[at] = 1;
			}
			else{
				ans.push_back(l);
				l = 1;
				niv++;
				vi = 0;
			}
		}
		vis2[v[i]] = min(vis2[v[i]], niv);
		qtd[v[i]]--;
		at = v[i];
	}
	ans.push_back(l);

	printf("%d\n", (int)ans.size());
	printf("%d", ans[0]);
	for(i = 1; i < (int)ans.size(); i++)
		printf(" %d", ans[i]);
	printf("\n");

	return 0;
}