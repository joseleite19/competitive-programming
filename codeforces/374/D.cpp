#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long v[200005];

class Segtree{
	vector<long long> st;
	int n;

	bool cmp(int p1, int p2){
		if(st[p1] == -1) return 0;
		if(st[p2] == -1) return 1;
		return abs(v[ st[p1] ] ) < abs(v[ st[p2] ]);
	}

	void update(int p, int L, int R, int i, long long vv){
		if(i < L || R < i) return;
		if(L == i && i == R){
			st[p] = i;
			if(v[i] >= 0) v[i] += vv;
			else v[i] -= vv;
			return;
		}
		int mid = (L+R)/2;
		if(i <= mid) update(2*p, L, mid, i, vv);
		else update(2*p+1, mid+1, R, i, vv);

		if(cmp(2*p, 2*p+1)) st[p] = st[2*p];
		else st[p] = st[2*p+1];
	}

public:
	int query(){
		return st[1];
	}
	void update(int i, long long vv){
		update(1, 0, n-1, i, vv);
	}

	Segtree(int size){
		n = size;
		st.assign(8*n, -1);
	}
};

int main(){
	int n, k;
	long long x;

	scanf("%d %d %lld", &n, &k, &x);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	if(n == 1){
		v[0] -= k*x;
		printf("%lld\n", v[0]);
		return 0;
	}

	int idl = 0;
	int aux = 0;
	for(int i = 0; i < n; i++){
		if(v[idl] > v[i]) idl = i;
		if(v[i] < 0) aux++;
	}

	Segtree s(n);
	for(int i = 0; i < n; i++) s.update(i, 0);
	
	if(v[idl] >= 0){
		int tmp = min(k, (int)(v[idl] / x + 1));
		s.update(idl, -x*tmp);
		k -= tmp;
		aux++;
	}
	if(aux > 0 && aux % 2 == 0){
		int p = s.query();
		int tmp = min(k, (int)(abs(v[p]) / x) + 1);
		s.update(p, -x*tmp);
		k -= tmp;
	}

	for(int i = 0; i < k; i++) s.update(s.query(), x);

	printf("%lld", v[0]);
	for(int i = 1; i < n; i++)
		printf(" %lld", v[i]);
	printf("\n");


	return 0;
}