#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int n;
int x[404];

double q[404];
int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", x+i);

	if(n == 2){
		printf("0.0000000\n");
		for(int i = 0; i < n; i++)
			printf("%d.0000000 ", x[i]);
		printf("\n");
		return 0;
	}

	for(int i = 0; i < n; i++)
		q[i] = x[i];

	double best = 1e50;
	pair<int, int> id = mp(0, 0);
	pair<int, int> tmp;
	double qe;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			tmp.ff = i, tmp.ss = j;
			double dist = x[j] - x[i];
			dist = dist / (j - i);
			double total = 0;

			for(int k = 0; k < n; k++){
				// if(k == i || k == j) continue;
				double w = x[i] + (k - i)*dist;
				total += fabs(w - x[k]);
			}
			if(total < best){
				best = total;
				qe = dist;
				id = tmp;
			}
		}
	}

	printf("%.20lf\n", best);

	// printf("%lf %d %d\n", qe, id.ff, id.ss);

	for(int i = 0; i < n; i++){
		printf("%.20lf ", x[id.ff] + (i - id.ff)*qe);
	}

	printf("\n");







	return 0;
}