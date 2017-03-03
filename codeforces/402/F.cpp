#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

vector<vector<pair<int, int> > > g;

map<char, int> trie[2*300005];
int ptr = 1;

int h[300005], ans[300005], sz[300005], mark[2*300005];

void count_size(int u, int p, int state){
	sz[state] = 1;

	for(int i = 0; i < (int)g[u].size(); i++){
		int v = g[u][i].ff;
		if(v == p) continue;
		char c = g[u][i].ss;

		if(!trie[state].count(c))
			trie[state][c] = ptr++;

		int newstate = trie[state][c];

		h[newstate] = h[state] + 1;
		count_size(v, u, newstate);
		sz[state] += sz[newstate];
	}
}

int merge(int u, int big){
	int ret = 0;

	for(map<char, int>::iterator it = trie[u].begin(); it != trie[u].end(); it++){
		int v = it->ss;
		char c = it->ff;

		if(!trie[big].count(c)) trie[big][c] = ptr++, mark[ trie[big][c] ] = 3;
		else ret++;

		mark[ trie[big][c] ] |= 1;
		ret += merge(v, trie[big][c]);
	};

	return ret;
}

void remove(int u){

	for(map<char, int>::iterator it = trie[u].begin(); it != trie[u].end(); ){

		map<char, int>::iterator it2 = it;
		it2++;

		if(mark[it->ss] == 3){
			mark[it->ss] = 0;
			remove(it->ss);
			trie[u].erase(it);
		}
		else if(mark[it->ss] == 1){
			mark[it->ss] = 0;
			remove(it->ss);
		}

		it = it2;
	}
}

void dfs(int u){

	int big = -1, mx = -1;
	for(map<char, int>::iterator it = trie[u].begin(); it != trie[u].end(); it++){
		dfs(it->ss);
		if(sz[ it->ss ] > mx) mx = sz[ it->ss ], big = it->ss;
	}

	int tmp = 0;
	if(big != -1){
		int oldptr = ptr;
		for(map<char, int>::iterator it = trie[u].begin(); it != trie[u].end(); it++){
			tmp++;
			if(it->ss == big) continue;

			tmp += merge(it->ss, big);
		}
		ptr = oldptr;
	}

	ans[ h[u] ] += tmp;

	if(big != -1) remove(big);
}

int main(){
	int n;

	scanf("%d", &n);
	g.assign(n, vector<pair<int, int> > ());

	int u, v;
	char c; 
	for(int i = 1; i < n; i++){
		scanf("%d %d %c", &u, &v, &c); u--, v--;
		g[u].push_back(mp(v, c));
		g[v].push_back(mp(u, c));
	}

	count_size(0, 0, 0);

	g.clear();

	dfs(0);

	int x = 0;
	for(int i = 0; i < n; i++)
		if(ans[i] > ans[x])
			x = i;

	printf("%d\n%d\n", n-ans[x], x+1);

	return 0;
}