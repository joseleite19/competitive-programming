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
const int N = 200005;

typedef pair <int,int> pii;

struct matriz{
	vector <vector <int> > mat;
	matriz(int n, int m): mat(n, vector<int>(m, 0)) {}
};

vector <matriz> v;
vector <pii> ordem;

int k,n,m;

bool resp = true;

vector <vector <int> > matriz_resp;

int t[N];

void solve(int indx){

	if(indx == k) return;

	int indx_anterior = ordem[indx-1].second;
	int indx_atual = ordem[indx].second;

	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < m; j++){
			if(v[indx_anterior].mat[i][j] == 1){
				if(v[indx_atual].mat[i][j] == 0){
					resp = false;
					return;
				}
				if (!matriz_resp[i][j]){
					matriz_resp[i][j] = k+2-indx;
				}
			}
			if(v[indx_atual].mat[i][j] == 1 && !matriz_resp[i][j]){
				matriz_resp[i][j] = k+1-indx;
			}
		}
	}
}

int main(){

	scanf("%d %d %d", &k, &n, &m);
	matriz_resp.assign(n, vector<int>(m, 0));

	for(int i = 0; i < k; i++){

		matriz aux(n,m);
		int cont = 0;
		char c;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf(" %c", &c);
				aux.mat[i][j] = c-'0';
				if(aux.mat[i][j] == 1) cont++;
			}
		}

		ordem.push_back(pii(cont,i));
		v.emplace_back(aux);
	}

	sort(ordem.begin(), ordem.end());

	for (int i = 1; i < k; i++)
		solve(i);

	if(!resp){
		return printf("IMPOSSIBLE\n"), 0;
	}


	for(int i = 0; i < k; i++)
		t[ ordem[i].ss ] = k+1-i;

	if(k == 1){
		t[0] = 1;
		matriz_resp = v[0].mat;
	}

	for(int i = 0; i < n; i++){
		printf("%d", matriz_resp[i][0]);
		for(int j = 1; j < m; j++)
			printf(" %d", matriz_resp[i][j]);
		printf("\n");
	}
	printf("%d", t[0]);
	for(int i = 1; i < k; i++)
		printf(" %d", t[i]);
	printf("\n");


    return 0;
}
