#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n, v[100005], cnt[100005];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);
	
	int ptr = n;

	for(int i = 0; i < n; i++){
		if(v[i] == ptr){
			printf("%d", v[i]);
			ptr--;
			while(ptr && cnt[ptr]){
				printf(" %d", ptr);
				ptr--;
			}
			printf("\n");
		}
		else{
			cnt[ v[i] ]++;
			printf("\n");
		}
	}

	return 0;
}