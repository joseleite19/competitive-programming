#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
int ans[1003];
int tmp[1003];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		ans[i] = 1000000004;

	int lastbit = 31 - __builtin_clz(n);

	for(; lastbit >= 0; lastbit--){
		vector<int> q1, q2;
		for(int i = 0; i < n; i++){
			if((1 << lastbit) & i)
				q1.push_back(i+1);
			else q2.push_back(i+1);
		}

		if(q1.size() > 0){
		
			printf("%d\n%d", (int)q1.size(), q1[0]);
			for(int i = 1; i < (int)q1.size(); i++)
				printf(" %d", q1[i]);
			printf("\n");
			fflush(stdout);
	
			for(int i = 0; i < n; i++){
				scanf("%d", tmp+i);
				if(!((1 << lastbit) & i)) ans[i] = min(ans[i], tmp[i]);
			}
		}

		if(q2.size() > 0){
			printf("%d\n%d", (int)q2.size(), q2[0]);
			for(int i = 1; i < (int)q2.size(); i++)
				printf(" %d", q2[i]);
			printf("\n");
			fflush(stdout);

			for(int i = 0; i < n; i++){
				scanf("%d", tmp+i);
				if((1 << lastbit) & i) ans[i] = min(ans[i], tmp[i]);
			}		
		}
	}

	printf("-1\n%d", ans[0]);
	for(int i = 1; i < n; i++)
		printf(" %d", ans[i]);
	printf("\n");
	fflush(stdout);

	return 0;
}