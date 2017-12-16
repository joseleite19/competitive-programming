#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

int vet[200100];

vector <int> g[200100];

int mark[200100];

int dfs(int a) {
	mark[a] = 1;

	for (int i : g[a]) {
		if (!mark[i])
			dfs(i);
	}
	return 0;
}

int main(){

	int n, k, x;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf(" %d", &vet[i]);
		vet[i]--;
	}

	scanf("%d", &k);

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			int a;
			scanf("%d", &a);
			a--;

			g[a].push_back(j);
		}
	}
	scanf("%d", &x);

	x--;

	int i;
	for (i = 0; i < n; i++) {
		if (vet[i] == x) {
			dfs(i);
			break;
		}
	}

	if(mark[0]) printf("YES\n");
	else printf("NO\n");

    return 0;
}
