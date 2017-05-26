#include <bits/stdc++.h>

using namespace std;

int vet[15], vet2[15];
long long certo[15];

class Segtree{
	vector<long long> st;
	vector<vector<int> > to;
	vector<vector<long long> > cnt;
	int n;

	void prop(int p){
        for(int d = 0; d < 15; d++) certo[d] = 0;
		for(int d = 0; d < 15; d++){
			vet[d] = to[p][ to[2*p][d] ];
			vet2[d] = to[p][ to[2*p+1][d] ];
			st[p] += -d*cnt[p][d] + to[p][d]*cnt[p][d];
		    certo[ to[p][d] ] += cnt[p][d];
		}
        for(int d = 0; d < 15; d++){
            to[2*p][d] = vet[d];
            to[2*p+1][d] = vet2[d];
            cnt[p][d] = certo[d];
            to[p][d] = d;
        }
	}

	long long query(int p, int L, int R, int i, int j){
		prop(p);
		if(L > j || i > R) return 0;
		
		if(L >= i && R <= j) return st[p];
		int mid = (L + R) / 2;

		return query(2*p, L,mid, i, j) + query(2*p+1,mid+1, R, i, j);
	}

	void update(int p, int L, int R, int i, int j, int x, int y){
		prop(p);
		if(L > j || i > R) return;
		if(L >= i && R <= j){
            to[p][x] = y;
            prop(p);
			return;
		}
		int mid = (L + R) / 2;
		update(2*p, L, mid, i, j, x, y);
		update(2*p+1,mid+1, R, i, j, x, y);
		st[p] = st[2*p] + st[2*p+1];
        for(int d = 0; d < 15; d++)
            cnt[p][d] = cnt[2*p][d] + cnt[2*p+1][d];
	}

	void update2(int p, int L, int R, int i, long long v){

		for(int d = 0; d < 15; d++)
			to[p][d] = d;

		if(L > i || i > R) return;
		
		long long tot = 1;
		long long copy = v;

		while(copy){
			// printf("%d %d %d %lld\n", L, R, copy%10, tot);
			cnt[p][copy%10] += tot;

			tot *= 10;
			copy /= 10;
		}

		if(L == i && R == i){
			st[p] = v;
			return;
		}
		int mid = (L + R) / 2;
		update2(2*p, L, mid, i, v);
		update2(2*p+1,mid+1, R, i, v);
		st[p] = st[2*p] + st[2*p+1];
	}

public:
	Segtree(int sz) : n(sz), st(8*(sz+10), 0), cnt(8*(sz+10), vector<long long>(15, 0LL)), to(8*(sz+10), vector<int>(15, 0)) {}

	void update(int i, int j, int x, int y){
		update(1, 1, n, i, j, x, y);
	}

	void update2(int i, long long v){
		update2(1, 1, n, i, v);
	}

	long long query(int i, int j){
		return query(1, 1, n, i, j);
	}

};

int main(){
	int n, q, x;

	scanf("%d %d", &n, &q);

	Segtree st(n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		st.update2(i, x);
	}

	int l, r, y;

	while(q--){
		int t;
		scanf("%d", &t);

		if(t == 1){
			scanf("%d %d %d %d", &l, &r, &x, &y);
			st.update(l, r, x, y);
		}
		else{
			scanf("%d %d", &l, &r);
			printf("%lld\n", st.query(l, r));
		}
	}


	return 0;
}
