#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define MOD 1000000009LL

using namespace std;

typedef long long ll;

const ll oo = 1000000000000000000;
const int N = 100005;
int n,m;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

typedef pair <int,int> pii;
typedef pair <pii,int> piii;

char p1[550][550];
char m1[550][550];
char m2[550][550];
char p2[550][550];

bool valido(int i, int j){

	if(i < 0 || j < 0 || i >= n || j >= m) return false;

	if(p1[i][j] == '.' and p2[i][j] == '.') return true;

	return false;
}

bool valido1(int i, int j){

	if(i < 0 || j < 0 || i >= n || j >= m) return false;

	return m1[i][j] == '.';
}

bool valido2(int i, int j){

	if(i < 0 || j < 0 || i >= n || j >= m) return false;

	return m2[i][j] == '.';
}

int bfs(int i, int j){

	queue <piii> q;

	q.push(piii(pii(i,j),0));

	while(!q.empty()){

		int i,j;

		piii aux = q.front();
		q.pop();

		i = aux.first.first;
		j = aux.first.second;
		int dist = aux.second;

		if(i == n-1 and j == m-1){
			return dist;
		}

		for(int x = 0; x < 4; x++){
			int ii = i + dx[x];
			int jj = j + dy[x];

			if(valido(ii,jj)){
				p1[ii][jj] = '#';
				p2[ii][jj] = '#';
				q.push(piii(pii(ii,jj),dist+1));
			}
		}		
	}

	return -3;
}

int bfs1(int i, int j){

	queue <piii> q;

	q.push(piii(pii(i,j),0));

	while(!q.empty()){

		int i,j;

		piii aux = q.front();
		q.pop();

		i = aux.first.first;
		j = aux.first.second;
		int dist = aux.second;

		if(i == n-1 and j == m-1){
			return dist;
		}

		for(int x = 0; x < 4; x++){
			int ii = i + dx[x];
			int jj = j + dy[x];

			if(valido1(ii,jj)){
				m1[ii][jj] = '#';
				q.push(piii(pii(ii,jj),dist+1));
			}
		}		
	}
	return -1;
}

int bfs2(int i, int j){

	queue <piii> q;

	q.push(piii(pii(i,j),0));

	while(!q.empty()){

		int i,j;

		piii aux = q.front();
		q.pop();

		i = aux.first.first;
		j = aux.first.second;
		int dist = aux.second;

		if(i == n-1 and j == m-1){
			return dist;
		}

		for(int x = 0; x < 4; x++){
			int ii = i + dx[x];
			int jj = j + dy[x];

			if(valido2(ii,jj)){
				m2[ii][jj] = '#';
				q.push(piii(pii(ii,jj),dist+1));
			}
		}		
	}
	return -6;
}

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &p1[i][j]);
			m1[i][j] = p1[i][j];
		}
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf(" %c", &p2[i][j]);
			m2[i][j] = p2[i][j];
		}
	}

	int respJunto = bfs(0,0);
	int resp1 = bfs1(0,0);
	int resp2 = bfs2(0,0);
	
	bool resposta = (respJunto == resp1) and (respJunto == resp2);

	if(resposta) printf("YES\n");
	else printf("NO\n");

    return 0;
}
