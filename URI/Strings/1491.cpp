#include <bits/stdc++.h>

using namespace std;

class SegTree{
	vector<int> stMin;
	vector<int> lazy;
	vector<int> occur;
	vector<int> occur2;
	int n;
	int len;

	void prop(int p, int L, int R){
		if(lazy[p]){
			if(L == R) bit[L] = ~bit[L] & ((1 << len)-1);

			int x = stMax[p];
			int y = stMin[p];

			if(y != 10){
				stMax[p] = len - y;
				stMin[p] = len - x;
				lazy[2*p] = (lazy[2*p] + 1) % 2;
				lazy[2*p+1] = (lazy[2*p+1] + 1) % 2;
			}
		}
		lazy[p] = 0;
	}

	int query(int p, int L, int R, int i, int j){
		prop(p, L, R);
		if(j < L || i > R) return 0;
		if(L >= i && j >= R) return stMax[p];
		int mid = (L+R)/2;

		int x = query(2*p, L, mid, i, j);
		int y = query(2*p+1, mid+1, R, i, j);

		return max(x, y);
	}

	void update(int p, int L, int R, int i, int j){
		prop(p, L, R);

		if(j < L || i > R) return;
		if(i <= L && R <= j){
			lazy[p] = 1;
			prop(p, L, R);
			return;
		}
		int mid = (L+R)/2;
		update(2*p, L, mid, i, j);
		update(2*p+1, mid+1, R, i, j);
		stMax[p] = max(stMax[2*p], stMax[2*p+1]);
		stMin[p] = min(stMin[2*p], stMin[2*p+1]);
	}

	void updateS(int p, int L, int R, int i, int comeco){
		prop(p, L, R);

		if(i < L || i > R) return;
		if(L == i && i == R){

			for(int k = comeco-i; k < len; k++){
				if(bit[i] & (1 << k)) bit[i] &= ~(1 << k);
				else bit[i] |= (1 << k);
			}

			stMax[p] = stMin[p] = __builtin_popcount(bit[i]);
			return;
		}
		int mid = (L+R)/2;
		updateS(2*p, L, mid, i, comeco);
		updateS(2*p+1, mid+1, R, i, comeco);

		stMax[p] = max(stMax[2*p], stMax[2*p+1]);
		stMin[p] = min(stMin[2*p], stMin[2*p+1]);
	}

public:
	vector<int> stMax;
	vector<int> bit;
	SegTree(int size, int l){
		n = size;
		len = l;
		stMax.assign(8*(n+10), 0);
		stMin.assign(8*(n+10), 10);
		lazy.assign(8*(n+10), 0);
		bit.assign(n, 0);
		occur2.assign(n, 0);
	}

	bool has(int L, int R){
		vector<int>::iterator it = lower_bound(occur.begin(), occur.end(), L);
		if(it == occur.end()) return 0;
		int id = *it;
		return (id + len - 1) <= R;
	}

	void put(int p, int b){
		bit[p] = b;
		occur2[p] = 1;
		occur.push_back(p);
		updateS(1, 0, n-1, p, p);
		updateS(1, 0, n-1, p, p);
	}

	void update(int i, int j){
		int k, q;
		int L = i, R = j-len+1;

		for(k = i-1; k >= max(0, i - len + 1); k--){
			if(occur2[k]){
				updateS(1, 0, n-1, k, i);
				updateS(1, 0, n-1, k, j+1);
			}
		}
		
		for(q = j; q >= max(i, j - len + 2); q--){
			if(occur2[q]){
				updateS(1, 0, n-1, q, q);
				updateS(1, 0, n-1, q, j+1);
			}
		}

		if(L <= R) update(1, 0, n-1, L, R);
	}

	int query(int i, int j){

		if(!has(i, j) || j - len + 1 < i) return -1;

		int ret = query(1, 0, n-1, i, j - len + 1);

		return ret;
	}
};


int main(){
	int n;
	char T[10], P[100005];

	while(scanf("%d %s %s", &n, T, P) == 3){
		int tam = strlen(P);
		int taml = strlen(T);

		SegTree st(tam, taml);

		for(int i = 0; i <= tam - taml; i++){
			bool equal = true;
			for(int j = 0; j < taml; j++)
				if(tolower(P[i+j]) != tolower(T[j])){
					equal = false;
					break;
				}
			if(equal){
				int bit = 0;
				for(int j = 0; j < taml; j++)
					if(P[i+j] != T[j])
						bit |= (1 << j);

				st.put(i, bit);
			}
		}

		int a, b;

		while(n--){
			scanf("%d %d", &a, &b); a--; b--;
			printf("%d\n", st.query(a, b));
			st.update(a, b);
		}
	}

	return 0;
}