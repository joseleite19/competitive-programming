#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

struct bit2D{
	int n, m;
	vector<vector<int> > ft;

	void add(int x, int y, int v){
		for(; x <= n; x += x&-x)
			for(int j = y; j <= m; j += j&-j)
				ft[x][j] += v;
	}

	int query(int x, int y){
		int ans = 0;
		for(; x > 0; x -= x&-x)
			for(int j = y; j > 0; j -= j&-j)
				ans += ft[x][j];
		return ans;
	}

	int query(int x0, int y0, int x1, int y1){
		return query(x1, y1) - query(x1, y0-1) - query(x0-1, y1) + query(x0-1, y0-1);
	}

	bit2D(int n = 0, int m = 0) : n(n), m(m), ft(n+1, vector<int>(m+1, 0)){}
};

int h, w;

char mat[502][502];

int main(){


	scanf("%d %d", &h, &w);

	bit2D bh(h, w), bw(h, w);

	for(int i = 0; i < h; i++)
		scanf(" %s", mat[i]);

	for(int i = 0; i < h; i++){
		for(int j = 1; j < w; j++){
			if(mat[i][j] != '.') continue;
			if(mat[i][j-1] != '.') continue;
			bh.add(i+1, j+1, 1);
		}
	}

	for(int i = 1; i < h; i++){
		for(int j = 0; j < w; j++){
			if(mat[i][j] != '.') continue;
			if(mat[i-1][j] != '.') continue;
			bw.add(i+1, j+1, 1);
		}
	}

	int q, x0, y0, x1, y1;

	scanf("%d", &q);

	while(q--){
		scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
		printf("%d\n", bh.query(x0, y0+1, x1, y1) + bw.query(x0+1, y0, x1, y1));
	}

	return 0;
}