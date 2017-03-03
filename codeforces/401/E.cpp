#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n;
pair<int, pair<int, int> > v[100005];

map<int, int> vai;
int ptr;

struct Segtree{
	int n;
	vector<long long> st;

	long long query(int p, int L, int R, int i, int j){
		if(i <= L && R <= j) return st[p];
		if(j < L || i > R) return 0;
		int mid = (L+R)/2;
		return max(query(2*p, L, mid, i, j), query(2*p+1, mid+1, R, i, j));
	}

	void update(int p, int L, int R, int i, long long v){
		if(i < L || i > R) return;
		if(L == i && i == R){
			st[p] = max(v, st[p]);
			return;
		}
		int mid = (L+R)/2;
		update(2*p, L, mid, i, v);
		update(2*p+1, mid+1, R, i, v);

		st[p] = max(st[2*p], st[2*p+1]);		
	}

	Segtree(int size = 0) : n(size), st(8*size, 0) {}

	void update(int i, long long v){
		update(1, 0, n-1, i, v);
	}
	long long query(int i, int j){
		return query(1, 0, n-1, i, j);
	}
};

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d %d %d", &v[i].ff, &v[i].ss.ff, &v[i].ss.ss);

	{
		vector<int> tmp;
		for(int i = 0; i < n; i++)
			tmp.push_back(v[i].ff), tmp.push_back(v[i].ss.ff);
		sort(tmp.begin(), tmp.end());

		for(int i = 0; i < tmp.size(); i++)
			if(!vai.count(tmp[i]))
				vai[ tmp[i] ] = ptr++;

		for(int i = 0; i < n; i++){
			v[i].ff = vai[ v[i].ff ];
			v[i].ss.ff = vai[ v[i].ss.ff ];
		}
	}

	Segtree st(ptr+10);

	for(int i = 0; i < n; i++)
		swap(v[i].ff, v[i].ss.ff);

	sort(v, v+n);

	for(int i = 0; i < n; i++)
		swap(v[i].ff, v[i].ss.ff);

	long long ans = 0;

	for(int i = 0; i < n; i++){
		long long tmp = st.query(v[i].ff+1, v[i].ss.ff);
		tmp += v[i].ss.ss;
		st.update(v[i].ss.ff, tmp);
		ans = max(ans, tmp);
	}


	printf("%lld\n", ans);

	return 0;
}