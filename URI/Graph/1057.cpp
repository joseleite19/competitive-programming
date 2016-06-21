#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int n;
char mapa[10][10];
long long dist[10][10][10][10][10][10];

bool obstaculo(const pii &p){
	return mapa[p.first][p.second] == '#';
}

long long &elemento(const vii v){
	return dist[v[0].first][v[0].second][v[1].first][v[1].second][v[2].first][v[2].second];
}

bool chegouNoFim(const vii v){
	return (mapa[v[0].first][v[0].second] == 'X' && mapa[v[1].first][v[1].second] == 'X' && mapa[v[2].first][v[2].second] == 'X');
}

int main(){
	int T;
	vii people(3);

	scanf("%d", &T);

	for(int t = 1; t <= T; t++){
		scanf("%d", &n);

		vii objetivos;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf(" %c", &mapa[i][j]);
				if(mapa[i][j] == 'A') people[0] = {i, j};
				if(mapa[i][j] == 'B') people[1] = {i, j};
				if(mapa[i][j] == 'C') people[2] = {i, j};
				if(mapa[i][j] == 'X') objetivos.pb({i, j});
			}
		}

		memset(dist, -1, sizeof dist);

		queue<vii>q;

		elemento(people) = 0;
		q.push({people[0],people[1],people[2]});

		long long ans = -1;
		int dx[] = {1, -1, 0, 0};
		int dy[] = {0, 0, 1, -1};
		while(!q.empty()){
			vii s = q.front(); q.pop();
			
			if(chegouNoFim(s)){
				ans = elemento(s);
				break;
			}

			vii v(3);
			const long long &dAntes = elemento(s);
			for(int i = 0; i < 4; i++){
				v[0] = {s[0].ff + dx[i], s[0].ss + dy[i]};
				v[1] = {s[1].ff + dx[i], s[1].ss + dy[i]};
				v[2] = {s[2].ff + dx[i], s[2].ss + dy[i]};

				for(int j = 0; j < 3; j++)
					if(v[j].ff < 0 || v[j].ff >= n || v[j].ss < 0 || v[j].ss >= n || obstaculo(v[j]))
						v[j].ff -= dx[i], v[j].ss -= dy[i];

				for(int j = 0, next = 1, nextnext = 2; j < 3; j++, next = (next+1)%3, nextnext = (nextnext+1)%3)
					if((v[j] == v[next] && v[next] == s[next]) || (v[j] == v[nextnext] && v[nextnext] == s[nextnext])) // se n fica em cima de uma que não pode se mover por exemplo A.CB nao vira .A.E (E é sobreposição de B e C)
						v[j].ff -= dx[i], v[j].ss -= dy[i];

				long long &el = elemento(v);
				if(el == -1 && v[0] != v[1] && v[0] != v[2] && v[1] != v[2]){
					el = dAntes + 1;
					q.push({v[0], v[1], v[2]});
				}				
			}
		}

		printf("Case %d: ", t);
		if(ans == -1) printf("trapped\n");
		else printf("%lld\n", ans);
	}

	return 0;
}