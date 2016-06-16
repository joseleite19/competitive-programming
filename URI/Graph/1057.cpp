#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;

#define mp make_pair
#define pb push_back
#define INF 1000000000000000007

int n;
char mapa[10][10];
long long dist[10][10][10][10][10][10];

bool obstaculo(const pii &p){
	return mapa[p.first][p.second] == '#';
}
pii cima(const pii &p){
	if(p.first+1 < n && !obstaculo({p.first+1, p.second})) return {p.first+1, p.second};
	return p;
}
pii baixo(const pii &p){
	if(p.first > 0 && !obstaculo({p.first-1, p.second})) return {p.first-1, p.second};
	return p;
}
pii dir(const pii &p){
	if(p.second+1 < n && !obstaculo({p.first, p.second+1})) return {p.first, p.second+1};
	return p;
}
pii esq(const pii &p){
	if(p.second > 0 && !obstaculo({p.first, p.second-1})) return {p.first, p.second-1};
	return p;
}

long long &elemento(const pii &a, const pii &b, const pii &c){
	return dist[a.first][a.second][b.first][b.second][c.first][c.second];
}

int main(){
	int T;
	pii people[3];

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

		// cout << people[0].first << " " << people[0].second << endl;
		// cout << people[1].first << " " << people[1].second << endl;
		// cout << people[2].first << " " << people[2].second << endl;

		queue<vii>q;

		for(int i = 0; i < n; i++) for(int j = 0; j < n; j++)
			for(int k = 0; k < n; k++) for(int q = 0; q < n; q++)
				for(int w = 0; w < n; w++) for(int e = 0; e < n; e++)
					dist[i][j][k][q][w][e] = INF;

		q.push({people[0],people[1],people[2]});
		elemento(people[0], people[1], people[2]) = 0;

		// printf("dasda\n"); fflush(stdout);
		int i = 0;
		long long ans1 = INF;
		while(!q.empty()){
			const pii a = q.front()[0];
			const pii b = q.front()[1];
			const pii c = q.front()[2]; q.pop();
			// cerr << elemento({2, 3}, {1, 2}, {3, 1}) << endl;

			pii aux1, aux2, aux3;
			const long long &dAntes = elemento(a, b, c);

			aux1 = cima(a);
			aux2 = cima(b);
			aux3 = cima(c);

			// cout << a.first << " " << a.second << endl;
			// cout << b.first << " " << b.second << endl;
			// cout << c.first << " " << c.second << endl << endl;

			long long &up = elemento(aux1, aux2, aux3);
			if(up == INF && aux1 != aux2 && aux1 != aux3 && aux2 != aux3){
				up = dAntes + 1;
				// if(aux1 == mp(5, 3) && aux2 == mp(4, 2) && aux3 == mp(5, 1)) {cerr << "dasda" << dist[5][3][4][2][5][1] << endl;}
				q.push({aux1, aux2, aux3});
			}
			
			aux1 = baixo(a);
			aux2 = baixo(b);
			aux3 = baixo(c);

			long long &down = elemento(aux1, aux2, aux3);
			if(down == INF && aux1 != aux2 && aux1 != aux3 && aux2 != aux3){
				down = dAntes + 1;
				q.push({aux1, aux2, aux3});
			}
			
			aux1 = dir(a);
			aux2 = dir(b);
			aux3 = dir(c);

			long long &rigth = elemento(aux1, aux2, aux3);
			if(rigth == INF && aux1 != aux2 && aux1 != aux3 && aux2 != aux3){
				rigth = dAntes + 1;
				q.push({aux1, aux2, aux3});
			}
			
			aux1 = esq(a);
			aux2 = esq(b);
			aux3 = esq(c);

			long long &left = elemento(aux1, aux2, aux3);
			if(left == INF && aux1 != aux2 && aux1 != aux3 && aux2 != aux3){
				left = dAntes + 1;
				q.push({aux1, aux2, aux3});
			}
			// cerr << q.size() << endl;
			// usleep(500000);
		}
		pii &a = objetivos[0];
		pii &b = objetivos[1];
		pii &c = objetivos[2];
		
		long long ans = min(min(min(min(min(elemento(a, b, c), elemento(a, c, b)), elemento(b, a, c)), elemento(b, c, a)), elemento(c, a, b)), elemento(c, b, a));
		printf("Case %d: ", t);
		if(ans == INF) printf("trapped\n");
		else printf("%lld\n", ans);
	}

	return 0;
}