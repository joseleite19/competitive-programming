#include <bits/stdc++.h>

#define ff first
#define ss second
#define oo (1000000000)

using namespace std;

class SegTree{
	vector<int> st;
	vector<int> last;
	int n;

	int left(int p){ return 2*p+1; }
	int right(int p){ return 2*p+2; }

	int query(int p, int L, int R, int i, int j){
		if(j < L || i > R) return 0;
		if(L >= i && R <= j) return st[p];
		int mid = (L+R)/2;
		return query(left(p), L, mid, i, j) + query(right(p), mid+1, R, i, j);
	}

	void update(int p, int L, int R, int i, int v, int pos){
		if(L == i && i == R){
			if(v == 0){
				st[p] = 0;
				last[p] = pos;
			}
			else if(v == -1){
				if(last[p] < pos) st[p]--;
			}
			else st[p]++;
			return;
		}
		if(i < L || R < i) return;
		int mid = (L+R)/2;
		if(i <= mid) update(left(p), L, mid, i, v, pos);
		else update(right(p), mid+1, R, i, v, pos);
		st[p] = st[left(p)] + st[right(p)];
	}
	
public:

	SegTree(int size){
		n = size;
		st.assign(4*(n), 0);
		last.assign(4*(n), 0);
	}

	int query(int i, int j){
		return query(0, 0, n-1, i, j);
	}

	void update(int i, int v, int pos = 0){
		update(0, 0, n-1, i, v, pos);
	}
};

int main(){
	int n, q, t, x;

	scanf("%d %d", &n, &q);

	SegTree st(n);

	vector<pair<int, int> > query1;

	int go[300005];

	int last = 0;

	for(int i = 0; i < q; i++){
		scanf("%d %d", &t, &x);
		if(t == 1){
			st.update(x-1, 1);
			query1.push_back(make_pair(x, i+1));
		}
		if(t == 2) st.update(x-1, 0, i+1);
		if(t == 3){
			for(int i = last; i < x; i++)
				st.update(query1[i].ff-1, -1, query1[i].ss);
			last = max(last, x);
		}
		printf("%d\n", st.query(0, n-1));
	}

	return 0;
}