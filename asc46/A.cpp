#include <bits/stdc++.h>

using namespace std;

struct point{
	long long x,y;
};

void file(){
	freopen("astronomy.in", "r", stdin);
	freopen("astronomy.out", "w", stdout);
}

int main(){
	file();

	int n;

	while(scanf("%d", &n), n){

		int x,y;

		typedef pair <long long,pair <long long,long long> > iii;

		map <iii,int> mapa;

		vector <point> v(n);

		for(int i = 0; i < n; i++){
			scanf("%lld %lld", &v[i].x, &v[i].y);	
		}

		for(int i = 0; i < n; i++){
			iii aux;
			aux.first = (v[i].x*v[i].x) + (v[i].y*v[i].y);
			for(int j = 0; j < n; j++){
				aux.second.first = (v[j].x*v[j].x) + (v[j].y*v[j].y);
				aux.second.second = ( (v[i].x-v[j].x)*(v[i].x-v[j].x) ) + ( (v[i].y-v[j].y)*(v[i].y-v[j].y) );
				// if(i == 1 and j == 2){
				// 	printf("%lld %lld %lld\n",aux.first, aux.second.first, aux.second.second );
				// }
				mapa[aux]++;
			}
		}

		int query;

		scanf("%d", &query);

		while(query--){

			iii aux;

			scanf("%lld %lld %lld", &aux.first, &aux.second.first, &aux.second.second);

			long long resp = mapa[aux];

			if(aux.first == aux.second.first) resp/=2;

			printf("%lld\n",resp );

		}

	}

	return 0;
}