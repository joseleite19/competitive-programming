#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int n;
long long t;

pair<long long, long long> v[100005];
char dir[100005];

long long dist[100005];

int ans[100005];

int vis[100005];

map<long long, set<pair<long long, int> > > linha;
map<long long, set<pair<long long, int> > > coluna;

void solve(){

	for(int i = 0; i < n; i++)
		dist[i] = 1LL << 63-1;

	priority_queue<pair<long long, int> > pq; // tempo, id

	pq.push(mp(0LL, 0));

	while(!pq.empty()){
		long long d = -pq.top().ff;
		int u = pq.top().ss;
		pq.pop();
		//printf("u %d\n",u);
		if(d > dist[u]){
			//printf("d %lld dist %lld\n",d,dist[u]);
			continue;	
		} 
        if(linha[v[u].ff].count(mp(v[u].ss,u))) linha[v[u].ff].erase(mp(v[u].ss,u));
        if(coluna[v[u].ss].count(mp(v[u].ff,u))) coluna[v[u].ss].erase(mp(v[u].ff,u));
		if(dir[u] == 'U'){

			set<pair<long long, int> >::iterator it = linha[ v[u].ff ].lower_bound(mp(v[u].ss, 0));

			for(; it != linha[ v[u].ff ].end(); it++){
				if(it->ss == u) continue;
		//		printf("U.%lld %d\n",it->ff,it->ss);
				// printf("it %d\n",it->ss);
				if(dir[it->ss] == 'U'){
					// printf("%d\n",it->ss);
					ans[it->ss] = ans[u];
					set<pair<long long, int> >::iterator it2 = it;
					if(linha[v[it->ss].ff].count(mp(v[it->ss].ss,it->ss))){
						//printf("uf\n");
						linha[v[it->ss].ff].erase(mp(v[it->ss].ss,it->ss));
					}
					it = it2;
					continue;
				}

				long long delta = it->ff - v[u].ss;
				if(delta == 0) continue;
				// d + delta
				long long tmp = d + delta;
				if(tmp < t && dist[it->ss] > tmp){
					dist[it->ss] = tmp;
					pq.push(mp(-tmp, it->ss));
				}
			}

//			while(1){
//				it = linha[ v[u].ff ].lower_bound(mp(v[u].ss, 0));
//				if(it == linha[ v[u].ff ].end()) break;
			//	linha[ v[u].ff ].erase(it);
//			}
			v[u].ss += (t - d);
		}
		if(dir[u] == 'D'){
			set<pair<long long, int> >::iterator it = linha[ v[u].ff ].lower_bound(mp(v[u].ss, 0));
			
			if(it != linha[ v[u].ff ].begin()){
				do{
					it--;
		//		printf("D.%lld %d\n",it->ff,it->ss);
					if(dir[it->ss] == 'D'){
						ans[it->ss] = ans[u];
						set<pair<long long, int> >::iterator it2 = it;
						if(linha[v[it->ss].ff].count(mp(v[it->ss].ss,it->ss))) linha[v[it->ss].ff].erase(mp(v[it->ss].ss,it->ss));
						it = it2;;
						continue;
					}
					long long delta = v[u].ss - it->ff;
					if(delta == 0) continue;

					long long tmp = d + delta;
					if(tmp < t && dist[it->ss] > tmp){
						dist[it->ss] = tmp;
						pq.push(mp(-tmp, it->ss));
					}
				}while(it != linha[ v[u].ff ].begin());


				// while(1){
				// 	it = linha[ v[u].ff ].lower_bound(mp(v[u].ss, 0));
				// 	if(it == linha[ v[u].ff ].begin()) break;
				// 	it--;
				// //	linha[ v[u].ff ].erase(it);
				// }
			}
			v[u].ss -= (t - d);
		}
		if(dir[u] == 'L'){
			set<pair<long long, int> >::iterator it = coluna[ v[u].ss ].lower_bound(mp(v[u].ff, 0));
			
		//	printf("L\n");
			if(it != coluna[ v[u].ss ].begin()){
				do{
					it--;
					if(dir[it->ss] == 'L'){
						ans[it->ss] = ans[u];
						set<pair<long long, int> >::iterator it2 = it;
						if(coluna[v[it->ss].ss].count(mp(v[it->ss].ff,it->ss))) coluna[v[it->ss].ss].erase(mp(v[it->ss].ff,it->ss));
						it = it2;						
						it--;
						continue;
					}
		//		printf("L.%lld %d\n",it->ff,it->ss);
					long long delta = v[u].ff - it->ff;
					if(delta == 0) continue;

					long long tmp = d + delta;
					if(tmp < t && dist[it->ss] > tmp){
						dist[it->ss] = tmp;
						pq.push(mp(-tmp, it->ss));
					}
				}while(it != coluna[ v[u].ss ].begin());


				// while(1){
				// 	it = coluna[ v[u].ss ].lower_bound(mp(v[u].ff, 0));
				// 	if(it == coluna[ v[u].ss ].begin()) break;
				// 	it--;
				// 	///coluna[ v[u].ss ].erase(it);
				// }
			}
			v[u].ff -= (t - d);
		}
		if(dir[u] == 'R'){
			set<pair<long long, int> >::iterator it = coluna[ v[u].ss ].lower_bound(mp(v[u].ff, 0));
		//	printf("R\n");
			for(; it != coluna[ v[u].ss ].end(); it++){
		//		printf("R.%lld %d\n",it->ff,it->ss);
				if(dir[it->ss] == 'R'){
					ans[it->ss] = ans[u];
					set<pair<long long, int> >::iterator it2 = it;
					if(coluna[v[it->ss].ss].count(mp(v[it->ss].ff,it->ss))) coluna[v[it->ss].ss].erase(mp(v[it->ss].ff,it->ss));
					it = it2;
					continue;
				}
				long long delta = it->ff - v[u].ff;
		// printf("%d\n", u);
				// d + delta
				if(delta == 0) continue;
				long long tmp = d + delta;
				if(tmp < t && dist[it->ss] > tmp){
					dist[it->ss] = tmp;
					pq.push(mp(-tmp, it->ss));
				}
			}

// 			while(1){
// 				it = coluna[ v[u].ss ].lower_bound(mp(v[u].ff, 0));
// 				if(it == coluna[ v[u].ss ].end()) break;
// 				//coluna[ v[u].ss ].erase(it);
//			}
			v[u].ff += (t - d);
		}
	}
}

int main(){

	scanf("%d %lld", &n, &t);

	for(int i = 0; i < n; i++){
		scanf("%lld %lld %c", &v[i].ff, &v[i].ss, dir+i);
		linha[ v[i].ff ].insert(mp(v[i].ss, i));
		coluna[ v[i].ss ].insert(mp(v[i].ff, i));
		ans[i] = i;
	}

	solve();

	for(int i = 0; i < n; i++)
		printf("%lld %lld\n", v[ans[i]].ff, v[ans[i]].ss);


	return 0;
}