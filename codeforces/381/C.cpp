#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

pair<int, int> a[100005];

class SegTree{
	vector<int> st, st2, id;
	vector<int> lazy;
	int n;

	void prop(int p){
		if(lazy[p]){
			st[p] = lazy[p];
			lazy[2*p] = lazy[p];
			lazy[2*p+1] = lazy[p];
			lazy[p] = 0;
		}
	}

	void update(int p, int L, int R, int i, int v){
		// prop(p);

		if(i < L || i > R) return;
		if(i == L && R == i){
			st[p] = v;
			st2[p] = v;
			id[p] = L;
			return;
		}

		int mid = (L+R)/2;

		update(2*p, L, mid, i, v);
		update(2*p+1, mid+1, R, i, v);

		st[p] = min(st[2*p], st[2*p+1]);

		if(st2[2*p] > st2[2*p+1]) id[p] = id[2*p];
		else id[p] = id[2*p+1];
		
		st2[p] = max(st[2*p], st[2*p+1]);
	}
	
	int query(int p, int L, int R, int i, int j){
		// prop(p);

		if(j < L || i > R) return oo;
		if(i <= L && R <= j) return st[p];

		int mid = (L+R)/2;

		return min(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
	}
	
	pair<int, int> get(int p, int L, int R, int i, int j){
		// prop(p);

		if(j < L || i > R) return mp(0, 0);
		if(i <= L && R <= j) return mp(st2[p], id[p]);

		int mid = (L+R)/2;

		return max(get(2*p, L, mid, i, j), get(2*p+1, mid+1, R, i, j));
	}

public:

	SegTree(int sz){
		n = sz;
		st.assign(16*n, 0);
		st2.assign(16*n, 0);
		id.assign(16*n, 0);
		lazy.assign(16*n, 0);
	}

	int query(int i, int j){
		return query(1, 1, n, i, j);
	}
	
	int get(int i, int j){
		pair<int, int> ret = get(1, 1, n, i, j);

		int ans = ret.ff;
		if(ret.ss - ret.ff + 1 < i){
			// printf("asd %d %d %d %d\n", ret.ss, ret.ff, i, j);
			ans = get(1, 1, n, ret.ss+1, j).ff;
		}

		return ans;
	}

	void update(int i, int v){
		update(1, 1, n, i, v);
	}

};

bool cmp(const pair<int, int> a, const pair<int, int> b){
	int x = a.ss - a.ff, y = b.ss - b.ff;
	return x < y;
}

int prox[100005];
map<int, int> num[100005];
bool query(int p, int l, int r){
	map<int, int>::iterator it = num[p].lower_bound(l);
	return it != num[p].end() && (*it).ss <= r;
}

int ans[100005];

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	for(int i = 0; i <= n+1; i++)
		prox[i] = i+1;

	for(int i = 0; i < m; i++)
		scanf("%d %d", &a[i].ff, &a[i].ss);

	sort(a, a+m, cmp);

	SegTree st(n);

	for(int i = 1; i <= n; i++) st.update(i, 0);

	int mex = 1e9;

	for(int i = 0; i < m; i++){
		int L = a[i].ff, R = a[i].ss;
		int num = st.query(L, R);
		// printf(".%d %d\n", L, R);
		// for(int i = 1; i <= n; i++)
		// 	printf("%d ", prox[i]);
		// printf("\n");
		prox[L-1] = R+1;
		for(int x = L; x <= R; ){
			int tmp = prox[x];

			ans[x] = num;
			st.update(x, num+1);
			// printf("%d %d %d %d %d\n", x, num, R, prox[x], prox[3]);
			// num = max(st.query(L, x), st.query(x, R));
			num = st.get(L, R);
			printf("%d %d\n", x, num);
			// if(L == 1) printf("%d %d\n", st.query(L, x), st.query(x, R));

			prox[x] = R+1;
			if(prox[prox[x]] != prox[x]+1)
				prox[x] = prox[prox[x]];

			x = tmp;
		}
		// for(int i = 1; i <= n; i++)
		// 	printf("%d ", prox[i]);
		// printf("\n");
		// for(int i = 1; i <= n; i++)
		// 	printf("#%d %d\n", i, st.get(i,i));
		printf(".%d %d\n", st.get(L, R), num);
		mex = min(mex, st.get(L, R));
	}

	printf("%d\n", mex);
	for(int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	printf("\n");


	return 0;
}