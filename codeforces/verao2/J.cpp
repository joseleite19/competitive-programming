#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long v[10];
long long tot = 0;
int n, m;

void run(){
	for(int i = 0; i < n; i++){
		int k = rand()%m + 1;
		v[k] += (m - k + 3);
		tot += (m - k + 3);
	}
	
}

int main(){

	scanf("%d %d", &n, &m);

	srand(time(0));
	for(int i = 0; i < 1000000; i++)
		run();

	for(int i = 1; i <= m; i++)
		printf("%lf\n", double(v[i])/tot);



	return 0;
}