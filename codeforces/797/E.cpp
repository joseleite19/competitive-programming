#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, v[100005];
int ans[100005][500];

int comp(int i, int k, int save){
	if(i >= n) return 0;
	if(save){
		if(ans[i][k]) return ans[i][k];
		return ans[i][k] = 1+comp(i+v[i]+k, k, save);
	}
	return 1+comp(i+v[i]+k, k, save);
}

int main(){

	printf("%d\n", 0 or 1 and 1);

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	for(int k = 1; k < 500; k++){
		for(int i = 0; i < n; i++){
			if(!ans[i][k]){
				ans[i][k] = comp(i, k, 1);
			}
		}
	}

	int q, p, k;

	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &p, &k); p--;
		printf("%d\n", k < 500 ? ans[p][k] : comp(p, k, 0));
	}


	return 0;
}