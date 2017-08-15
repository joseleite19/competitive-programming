#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int t, n, m;

int pass;

int mark[102][102][102][102];
int dist[102][102][102][102];

int bfs(int hd, int ad, int hk, int ak, int b, int d){
	pair<pair<pair<int, int>, int>, int> tmp, tmp2;
	queue<pair<pair<pair<int, int>, int>, int> > q;

	mark[hd][ad][hk][ak] = pass;
	dist[hd][ad][hk][ak] = 0;

	tmp = mp(mp(mp(hd, ad), hk), ak);
	q.push(tmp);

	while(!q.empty()){
		tmp = q.front(); q.pop();

		//atack
		tmp2 = tmp;
		tmp2.ff.ss -= tmp2.ff.ff.ss;
		if(tmp2.ff.ss <= 0) return dist[tmp.ff.ff.ff][tmp.ff.ff.ss][tmp.ff.ss][tmp.ss]+1;
		tmp2.ff.ff.ff -= tmp2.ss;

		if(tmp2.ff.ff.ff > 0){
			if(mark[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] != pass){
				mark[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] = pass;
				dist[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] = dist[tmp.ff.ff.ff][tmp.ff.ff.ss][tmp.ff.ss][tmp.ss]+1;
				q.push(tmp2);
			}
		}

		//buff
		tmp2 = tmp;
		tmp2.ff.ff.ss += b;
		tmp2.ff.ff.ff -= tmp2.ss;

		if(tmp2.ff.ff.ff > 0){
			if(mark[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] != pass){
				mark[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] = pass;
				dist[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] = dist[tmp.ff.ff.ff][tmp.ff.ff.ss][tmp.ff.ss][tmp.ss]+1;
				q.push(tmp2);
			}
		}

		//cure

		tmp2 = tmp;
		tmp2.ff.ff.ff = hd;
		tmp2.ff.ff.ff -= tmp2.ss;

		if(tmp2.ff.ff.ff > 0){
			if(mark[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] != pass){
				mark[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] = pass;
				dist[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] = dist[tmp.ff.ff.ff][tmp.ff.ff.ss][tmp.ff.ss][tmp.ss]+1;
				q.push(tmp2);
			}
		}

		//debuff
		tmp2 = tmp;
		tmp2.ss = max(0, tmp2.ss - d);
		tmp2.ff.ff.ff -= tmp2.ss;

		if(tmp2.ff.ff.ff > 0){
			if(mark[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] != pass){
				mark[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] = pass;
				dist[tmp2.ff.ff.ff][tmp2.ff.ff.ss][tmp2.ff.ss][tmp2.ss] = dist[tmp.ff.ff.ff][tmp.ff.ff.ss][tmp.ff.ss][tmp.ss]+1;
				q.push(tmp2);
			}
		}
	}

	return -1;
}


int main(){
	int hd, ad, hk, ak, b, d;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		pass++;
		scanf("%d %d %d %d %d %d", &hd, &ad, &hk, &ak, &b, &d);

		int ans = bfs(hd, ad, hk, ak, b, d);
		
		printf("Case #%d: ", tc);
		if(ans == -1) printf("IMPOSSIBLE\n");
		else printf("%d\n", ans);

	}

	return 0;
}