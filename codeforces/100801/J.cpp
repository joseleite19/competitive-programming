#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

#define oo 1000000000
#define OO 1000000000000000000

void file(){
	freopen("journey.in", "r", stdin);
	freopen("journey.out", "w", stdout);
}

class SegTree{
	vector<long long> st;
	int n;

	long long query(int p, int L, int R, int i, int j){
		if(L >= i && R <= j) return st[p];
		if(i > R || j < L) return OO;
		int mid = (L + R) / 2;
		
		return min(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
	}

	void update(int p, int L, int R, int i, long long v){
		if(i > R || i < L) return;
		if(L == i && i == R){
			st[p] = v;
			return;
		}
		int mid = (L + R) / 2;
		update(2*p, L, mid, i, v);
		update(2*p+1, mid+1, R, i, v);
		st[p] = min(st[2*p], st[2*p+1]);
	}

public:
	SegTree(int size){
		n = size;
		st.assign(4*(n+5), OO);
	}
	long long query(int i, int j){
		return query(1, 0, n-1, i, j);
	}
	void update(int i, long long v){
		update(1, 0, n-1, i, v);
	}
};

int d[50005], t;

long long f(int r, int n){
	SegTree st(n);

	st.update(0, 0);
	for(int i = 1; i < n; i++)
		st.update(i, st.query(max(0, i-r), i-1) + d[i]);
	return st.query(n-1, n-1) + n-1;
}

int main(){
	file();
	int n;
	int p[50005];
	scanf("%d %d", &n, &t);


	for(int i = 0; i < n-1; i++)
		scanf("%d", p+i);

	d[0] = d[n-1] = 0;
	for(int i = 1; i < n-1; i++)
		scanf("%d", d+i);

	int hi = n-2, lo = 0;
	
	while(hi > lo){
		int mid = (hi+lo)/2;
		if(f(mid, n) <= t) hi = mid;
		else lo = mid+1;
	}

	int ans = oo;
	for(int i = hi-1; i < n-1; i++)
		ans = min(ans, p[i]);

	printf("%d\n", ans);

	return 0;
}