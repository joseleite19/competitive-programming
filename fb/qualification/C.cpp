#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

double tt[21][22][404];

int main(){
	int t;

	double tmp;
	int id[] = {4, 6, 8, 10, 12, 20};

	for(int i = 0; i < 6; i++){
		int v = id[i];
		tmp = 1.0/v;
		for(int j = 1; j <= v; j++) tt[v][1][j] = tmp;
		for(int jog = 1; jog <= 20; jog++){
			for(int j = 1; j < 404; j++){
				if(!tt[v][jog][j]) continue;
				for(int prox = 1; prox <= v; prox++)
					tt[v][jog+1][j+prox] += tt[v][jog][j]*tmp;
			}
		}
	}

	for(int i = 0; i < 6; i++){
		int v = id[i];
		for(int jog = 1; jog <= 20; jog++){
			for(int j = 402; j >= 0; j--)
				tt[v][jog][j] += tt[v][jog][j+1];
		}
	}

	scanf("%d", &t);

	int h, s;

	for(int tc = 1; tc <= t; tc++){
		scanf("%d %d", &h, &s);

		double ans = 0;
		while(s--){
			int x, y, z = 0;
			scanf("%dd%d", &x, &y);
			char c = getchar();
			if(c == '-'){
				scanf("%d", &z);
				z = -z;
			}
			if(c == '+'){
				scanf("%d", &z);
				z = z;
			}
			double tmp = 0;

			int asdf = max(1, h-z);
			if(asdf < 404) tmp = tt[y][x][asdf];

			ans = max(ans, tmp);
		}
		printf("Case #%d: %lf\n", tc, ans);
	}
	
	return 0;
}