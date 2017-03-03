#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD 1000003

using namespace std;

map<char, int> trie[100005];
int prox = 1;

int fail[100005];
int fim[100005];

void add(char *s, int x){
	int ptr = 0;
	for(int i = 0; s[i]; i++){
		if(!trie[ptr].count(s[i])) trie[ptr][ s[i] ] = prox++;
		ptr = trie[ptr][ s[i] ];
	}
	fim[ptr] = x;
}

void fix(){
	queue<int> q;

	q.push(0);

	while(!q.empty()){
		int u = q.front(); q.pop();

		for(map<char, int>::iterator it = trie[u].begin(); it != trie[u].end(); it++){
			char c = it->ff;
			int v = it->ss;

			int ptr = fail[u];

			while(ptr && !trie[ptr].count(c)) ptr = fail[ptr];
			if(trie[ptr].count(c)) ptr = trie[ptr][c];

			fail[v] = ptr != v ? ptr : 0;

			q.push(v);
		}
	}
}

int ans[100005];
int inc(int s, char c){
	while(s && !trie[s].count(c)){
		if(fim[s]) ans[ fim[s] ]++;
		s = fail[s];
	}
		if(fim[s]) ans[ fim[s] ]++;
	if(trie[s].count(c)) s = trie[s][c];
		if(fim[s]) ans[ fim[s] ]++;
	return s;
}

long long dp[25][2][2][2][1100]; // size, low, upper, digit, state
bool mark[25][2][2][2][1100];

map<char, char> code;

long long f(int size, int low, int up, int dig, int state){
	long long &ans = dp[size][low][up][dig][state];

	if(mark[size][low][up][dig][state]) return ans;
	mark[size][low][up][dig][state] = 1;

	ans = 0;

	// if(!trie[state].size()) return ans;
	if(fim[state]) return ans;
	if(size == 0) return ans = low && up && dig;

	// all letters
	for(char c = 'a'; c <= 'z'; c++){
		ans += f(size-1, true, up, dig, inc(state, c));
		ans %= MOD;
		ans += f(size-1, low, true, dig, inc(state, c));
		ans %= MOD;
	}
	
	ans += f(size-1, low, up, true, inc(state, 'o'));
	ans %= MOD;
	ans += f(size-1, low, up, true, inc(state, 'i'));
	ans %= MOD;
	ans += f(size-1, low, up, true, inc(state, 'e'));
	ans %= MOD;
	ans += f(size-1, low, up, true, inc(state, 's'));
	ans %= MOD;
	ans += f(size-1, low, up, true, inc(state, 't'));
	ans %= MOD;
	ans += (5*f(size-1, low, up, true, 0)) % MOD;
	ans %= MOD;

	return ans;
}

char s[100005];
char p[100005];

int main(){

	int k = 0;
	int n;
	scanf("%d", &k);

	while(k--){

		prox = 1;

		for(int i = 0; i < 100005; i++)
			trie[i].clear();
		memset(fim, 0, sizeof fim);
		memset(ans, 0, sizeof ans);

		scanf(" %s", s);

		int m;

		scanf("%d", &m);

		for(int i = 0; i < m; i++){
			scanf(" %s", p);
			add(p, i+1);
			// int ptr = 0;
			// int can = true;;
			// for(int j = 0; s[j]; j++){
			// 	ptr = inc(ptr, s[j]);
			// 	if(!ptr) can = false;
			// }
			// if(can) printf("y\n");
			// else printf("n\n");
		}
		fix();

		int ptr = 0;
		for(int i = 0; s[i]; i++){
			ptr = inc(ptr, s[i]);
			if(fim[ptr]) ans[ fim[ptr] ]++;
		}
		for(int i = 1; i <= m; i++)
			printf("%d\n", ans[i]);
		for(int i = 1; i <= m; i++)
			printf("%c\n", ans[i] ? 'y' : 'n');
	}

	// long long ans = 0;

	// for(int i = A; i <= B; i++){
	// 	ans = (ans + f(i, false, false, false, 0)) % MOD;
	// }
	// printf("%lld\n", ans);

	// for(int i = 0; i < prox; i++){
	// 	printf("%d,%d:", i, fail[i]);
	// 	for(map<char, int>::iterator it = trie[i].begin(); it != trie[i].end(); it++)
	// 		printf(" (%c, %d)", it->ff, it->ss);
	// 	printf("\n");
	// }

	return 0;
}