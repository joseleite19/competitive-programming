#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){

	int t;
	int x[20004], y[20004];

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){
		int n;

		scanf("%d", &n);


		for(int i = 0; i < n; i++)
			scanf("%d", x+i);
		for(int i = 0; i < n; i++)
			scanf("%d", y+i);

		long long tmp1 = 0, tmp2 = 0;

		for(int i = 0; i < n; i++){
			if(i & 1){
				tmp1 += x[i];
				tmp2 += y[i];
			}
			else{
				tmp2 += x[i];
				tmp1 += y[i];
			}
		}
		printf("%lld\n", min(tmp1, tmp2));

	}

	return 0;
}