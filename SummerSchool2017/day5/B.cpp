#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int n;
pair<long long, long long> v[100005];



int p[100005];

int f(int x){
	if(x == p[x]) return x;
	return p[x] = f(p[x]);
}

vector<int> up, low;

long long D(int i, int j, int k){
	long long ret = v[i].ff * v[j].ss;
	ret += v[j].ff * v[k].ss;
	ret += v[k].ff * v[i].ss;

	ret -= v[i].ss * v[j].ff;
	ret -= v[j].ss * v[k].ff;
	ret -= v[k].ss * v[i].ff;
	return ret;
}

void convex(){
	low.push_back(0);


	for(int i = 1; i < n; i++){
		while(low.size() >= 2 && D(low[ low.size()-2 ], low[ low.size()-1 ], i) >= 0) low.pop_back();
		low.push_back(i);
	}

	up.push_back(n-1);
	for(int i = n-2; i >= 0; i--){
		while(up.size() >= 2 && D(up[ up.size()-2 ], up[ up.size()-1 ], i) >= 0) up.pop_back();
		up.push_back(i);
	}
}

long long maior[100005];

long long dist(int i, int j){
	return abs(v[i].ff - v[j].ff) + abs(v[i].ss - v[j].ss);
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld %lld", &v[i].ff, &v[i].ss);

	// long long ans = 1000000000000000000;

	// for(int i = 0; i < n; i++){
	// 	long long tmp = 0;
	// 	for(int j = 0; j < n; j++){
	// 		tmp = max(tmp, dist(i, j));
	// 	}
	// 	ans = min(ans, tmp);
	// }
	// printf("%lld\n", ans);
	// return 0;

	

	// sort(v, v+n);
	// convex();

	// // if()

	// // for(int i = 0; i < (int)low.size(); i++)
	// // 	printf("#%d\n", low[i]);
	
	// // for(int i = 0; i < (int)up.size(); i++)
	// // 	printf(".#%d\n", up[i]);


	// for(int i = 0; i < n; i++){
	// 	if(low.size() <= 3){
	// 		for(int j = 0; j < low.size(); j++)
	// 			maior[i] = max(maior[i], dist(i, low[j]));
	// 		continue;
	// 	}
	// 	printf("%d\n", i);
	// 	long long d1, d2, d3, d4;
	// 	d1 = dist(i, low[0]);
	// 	d2 = dist(i, low[1]);
	// 	d3 = dist(i, low[ low.size()-2 ]);
	// 	d4 = dist(i, low[ low.size()-1 ]);

	// 	if(d1 <= d2 && d3 >= d4){ // busca ternaria da certo
	// 		int hi = low.size()-1, lo = 0;

	// 		while(lo+2 < hi){
	// 			int tmp = (hi - lo) / 3;
	// 			int mid1 = lo + tmp;
	// 			int mid2 = hi - tmp;
	// 			if(dist(i, low[mid1]) > dist(i, low[mid2])) hi = mid2-1;
	// 			else lo = mid1;
	// 		}

	// 		for(int j = lo; j <= hi; j++)
	// 			maior[i] = max(maior[i], dist(i, low[j]));
	// 	}
		
	// 	maior[i] = max(maior[i], dist(i, low[0]));
	// 	maior[i] = max(maior[i], dist(i, low[ low.size()-1 ]));
	// }


	// for(int i = 0; i < n; i++){
	// 	if(up.size() <= 3){
	// 		for(int j = 0; j < up.size(); j++)
	// 			maior[i] = max(maior[i], dist(i, up[j]));
	// 		continue;
	// 	}
	// 	long long d1, d2, d3, d4;
	// 	d1 = dist(i, up[0]);
	// 	d2 = dist(i, up[1]);
	// 	d3 = dist(i, up[ up.size()-2 ]);
	// 	d4 = dist(i, up[ up.size()-1 ]);

	// 	if(d1 <= d2 && d3 >= d4){ // busca ternaria da certo
	// 		int hi = up.size()-1, lo = 0;

	// 		while(lo+2 < hi){
	// 			int tmp = (hi - lo) / 3;
	// 			int mid1 = lo + tmp;
	// 			int mid2 = hi - tmp;
	// 			if(dist(i, up[mid1]) > dist(i, up[mid2])) hi = mid2-1;
	// 			else lo = mid1;
	// 		}

	// 		for(int j = lo; j <= hi; j++)
	// 			maior[i] = max(maior[i], dist(i, up[j]));
	// 	}
	// 	maior[i] = max(maior[i], dist(i, up[0]));
	// 	maior[i] = max(maior[i], dist(i, up[ up.size()-1 ]));
	// }


	// ans = 1000000000000000000;
	// for(int i = 0; i < n; i++)
	// 	ans = min(ans, maior[i]);

	// printf("%lld\n", ans);

	for(int i = 0; i < n; i++)
		p[i] = i;

	vector<pair<long long, pair<int, int>> > e;

	// int tmp2 = 1000000;
	for(int i = 0; i < n; i++){
		int mpt = 0;
		for(int j = 0; j < n; j++){
			if(j == i) continue;
			e.push_back(mp(abs(v[i].ff - v[j].ff) + abs(v[i].ss - v[j].ss), mp(i, j)));
			// ans = max(ans, abs(v[i].ff - v[j].ff) + abs(v[i].ss - v[j].ss));
			// mpt = max(mpt, abs(v[i].ff - v[j].ff) + abs(v[i].ss - v[j].ss));
			// printf("%d %d %d: %d %d %d %d\n", i, j, abs(v[i].ff - v[j].ss) + abs(v[i].ss - v[j].ss), v[i].ff, v[i].ss, v[j].ff, v[j].ss);
		}
		// printf("..%d - %d\n", i, mpt);

		// tmp2 = min(tmp2, mpt);
	}

	// printf("%d\n", tmp2);
	// printf("%d\n", ans);
	long long ans = 1000000000000000000;
	sort(e.begin(), e.end());
	for(int i = e.size()-1; i >= 0; i--){
		// printf("%d %d %d\n", e[i].ss.ff, e[i].ss.ss, e[i].ff);
		if(f(e[i].ss.ff) != f(e[i].ss.ss)){
			p[ f(e[i].ss.ff) ] = f(e[i].ss.ss);
			ans = min(ans, e[i].ff);
		}
	}
	printf("%lld\n", ans);



	return 0;
}