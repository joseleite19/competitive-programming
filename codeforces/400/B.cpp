#include <bits/stdc++.h>

using namespace std;

int n;
int ans[100005];
int ptr = 1;

bool n_prime[100005];
bool cnt[100005];

int main(){

	n_prime[0] = n_prime[1] = 1;
	for(int i = 2; i < 100005; i++){
		if(!n_prime[i]){
			for(int j = i+i; j < 100005; j += i)
				n_prime[j] = 1;
		}
	}

	scanf("%d", &n);

	// for(int i = 0; i < n; i++)
	// 	ans[i] = ptr;

	// for(int i = 0; i < n; i++){
	// 	if(!n_prime[i+2]){
	// 		for(int j = 2*(i+2); j <= n+1; j += (i+2)){
	// 			if(ans[i] == ans[j-2]){
	// 				ans[j-2] = ptr++;
	// 				printf("%d\n", j);
	// 			}
	// 		}
	// 	}
	// }

	if(n <= 2) printf("1\n");
	else printf("2\n");

	for(int i = 2; i <= n+1; i++)
		printf("%d ", 1+n_prime[i]);
	printf("\n");

	// printf("%d\n", ptr);

	// for(int i = 0; i < n; i++)
	// 	printf("%d ", ans[i]);
	// printf("\n");





	return 0;
}