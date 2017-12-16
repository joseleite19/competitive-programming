#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

pair<int, int> f(int n, int k){
	vector<int> v(n, 0);
	pair<int, int> ans = mp(-1, -1);

	int id = 0;
	int cnt = 0;
	// printf("%d -", n);
	// printf("%d\n", n);
	while(k--){
		id++;
		pair<int, int> tmp = mp(-1, -1);

		int pos = 0;

		for(int i = 0; i < n; i++){
			if(v[i]) continue;

			pair<int, int> np = mp(0, 0);
			for(int j = i-1; j >= 0; j--){
				if(v[j]) break;
				np.ff++;
			}
			for(int j = i+1; j < n; j++){
				if(v[j]) break;
				np.ss++;
			}

			if(min(np.ff, np.ss) > min(tmp.ff, tmp.ss) || (min(np.ff, np.ss) == min(tmp.ff, tmp.ss) && max(np.ff, np.ss) > max(tmp.ff, tmp.ss))){
				tmp = np;
				pos = i;
			}
		}

		v[pos] = 1;

		// printf("%d.%d(%s) | %d %d\n", id, pos, bin(pos).c_str(), tmp.ff, tmp.ss);
		// printf("%d %d\n", tmp.ff, tmp.ss);
		// assert(tmp.ss - tmp.ff == 0 || tmp.ss - tmp.ff == 1);
		// if(tmp.ff == 0 && tmp.ss == 0) cnt++;

		// printf(" %d", pos+1);
		if(ans.ff == -1){
			ans = tmp;
			cnt++;
		}
		else{
			if(ans != tmp){
				// printf(" %d", cnt);
				cnt = 0;
			}
			cnt++;
			ans = tmp;
		}
	}
	// printf("\n");
	// printf(" %d\n", cnt);

	return ans;
}

void put(map<pair<int, int>, int>& cnt, int range, int val){
	if(range){
		pair<int, int> id = mp(range/2, range/2);
		if(range % 2 == 0) id.ff--;
		cnt[ id ] += val;
	}
}

pair<int, int> g(int n, int k){
	map<pair<int, int>, int> cnt;

	put(cnt, n, 1);

	while(!cnt.empty()){
		pair<pair<int, int>, int> p = *cnt.rbegin();
		cnt.erase(cnt.rbegin()->ff);
		if(p.ss >= k) return p.ff;
		k -= p.ss;
		put(cnt, p.ff.ff, p.ss);
		put(cnt, p.ff.ss, p.ss);
	}

	return mp(0, 0);
}

int main(){

	int t, n, k;

	scanf("%d", &t);
	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d", &n, &k);
		pair<int, int> ret = g(n, k);

		printf("Case #%d: %d %d\n", tc, ret.ss, ret.ff);
	}

	return 0;
}