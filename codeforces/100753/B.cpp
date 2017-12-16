#include <bits/stdc++.h>
#define MAXN 20004

using namespace std;

int n;//, mat[10004][10004];

vector<int> g[MAXN];
bool vis[MAXN];
int match[MAXN];


int Aug(int l) {
	// return 1 if an augmenting path is found
	if (vis[l]) return 0; // return 0 otherwise
	vis[l] = 1;
	for (int j = 0; j < (int)g[l].size(); j++) {
		int r = g[l][j]; // edge weight not needed -> vector<vi> AdjList
		if (match[r] == -1 || Aug(match[r])) {
			match[r] = l; return 1; // found 1 matching
		}
	}
	return 0; // no matching
}

int maxBipartiteMatching() {
	int ans = 0;
	memset(match, -1, sizeof match);
	for(int i = 0; i < n; ++i) {
		memset(vis, 0, sizeof vis);
		if (Aug(i)) ans++;
	}
	return ans;
}
int main(){

	scanf("%d", &n);
	int k, x;

	for(int i = 0; i < n; i++){
		scanf("%d", &k);
		while(k--){
			scanf("%d", &x);
			g[i].push_back(x);
		}
	}

	printf("%d\n", n - maxBipartiteMatching());

	return 0;
}