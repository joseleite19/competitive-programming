#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int ptr = 1, n;
int v[10004];
int mat[10004][2];
int cnt[10004];
int h[10004];
int ind[10004];


void put(int id, int val, int i){
	if(!cnt[id]){
		// printf("%d %d\n", id, val);
		cnt[id] = val;
		ind[id] = i;
		return;
	}
	if(val > cnt[id]){
		if(!mat[id][0]) mat[id][0] = ptr++;
		put(mat[id][0], val, i);
	}
	else{
		if(!mat[id][1]) mat[id][1] = ptr++;
		put(mat[id][1], val, i);
	}
}

void dfs(int id){
	int ans = 0;
	if(mat[id][0]){
		dfs(mat[id][0]);
		ans = max(ans, h[ mat[id][0] ]);
	}
	if(mat[id][1]){
		dfs(mat[id][1]);
		ans = max(ans, h[ mat[id][1] ]);
	}
	h[id] = ans+1;
	// printf(".%d %d\n", id, h[id]);
}

pair<int, int> calc(int id){
	pair<int, int> ans = make_pair(-1, -1);
	if(mat[id][0]){
		pair<int, int> ret = calc(mat[id][0]);
		if(ret.ff > ans.ff) ans = ret;
		else if(ret.ff == ans.ff && ret.ss < ans.ss) ans = ret;
	}
	if(mat[id][1]){
		pair<int, int> ret = calc(mat[id][1]);
		if(ret.ff > ans.ff) ans = ret;
		else if(ret.ff == ans.ff && ret.ss < ans.ss) ans = ret;
	}
	pair<int, int> me = make_pair(abs(h[ mat[id][0] ] - h[ mat[id][1] ]), ind[id]);
	// printf("|%d %d %d %d\n", id, me.ff, h[ mat[id][0] ], h[ mat[id][1] ]);
	if(me.ff > ans.ff) ans = me;
	else if(me.ff == ans.ff && me.ss < ans.ss) ans = me;
	return ans;
}

int main(){
	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		scanf("%d", &n);
		ptr = 1;

		memset(mat, 0, sizeof mat);
		memset(cnt, 0, sizeof cnt);
		memset(ind, 0, sizeof ind);
		memset(h, 0, sizeof h);
		for(int i = 0; i < n; i++){
			scanf("%d", v+i);
			put(0, v[i], i);
		}

		dfs(0);
		h[0] = 0;
		printf("Bando #%d: %d\n\n", tc, v[ calc(0).ss ]);

		
	}

	return 0;
}