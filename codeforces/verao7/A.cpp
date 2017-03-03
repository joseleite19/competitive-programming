#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int v[200005];
int ans[200005];

int n;

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	for(int i = 0; i < n; i++){
		ans[i+v[i]-1] = max(ans[i+v[i]-1], v[i]);
	}

	int ptr = 0;

	for(int i = n-1; i >= 0; i--){
		ptr = max(ptr, ans[i]);
		ans[i] = ptr;
		ptr--;
	}

	for(int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");





	return 0;
}