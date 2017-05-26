#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo (1000000000)

using namespace std;

class Segtree{
	vector<long long> st;
	vector<int> op;
	int n;

	void update(int p, int L, int R, int i, long long v){
		if(L == R){
			op[p] = 1;
			st[p] = v;
			return;
		}
		int mid = (L+R)/2;
		if(i <= mid) update(2*p, L, mid, i, v), op[p] = op[2*p]^1;
		else update(2*p+1, mid+1, R, i, v), op[p] = op[2*p+1]^1;

		if(op[p]) st[p] = st[2*p] ^ st[2*p+1];
		else st[p] = st[2*p] | st[2*p+1];
	}

public:
	Segtree(int sz) : n(sz), st(2*sz, 0), op(2*sz, 0) {}

	long long get(){
		return st[1];
	}

	void update(int i, long long v){
		update(1, 1, n, i, v);
	}
};

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	Segtree st(1 << n);

	long long x;
	int b;
	for(int i = 1; i <= (1 << n); i++){
		scanf("%lld", &x);
		st.update(i, x);
	}

	for(int i = 0; i < m; i++){
		scanf("%d %lld", &b, &x);
		st.update(b, x);
		printf("%lld\n", st.get());
	}

	return 0;
}