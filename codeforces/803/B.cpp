#include <bits/stdc++.h>

using namespace std;

int d[200005], v[200005], n;

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	queue<int> q;

	for(int i = 0; i < n; i++){
		if(v[i]) d[i] = 1000000000;
		else{
			q.push(i);
		}
	}

	while(!q.empty()){
		int u = q.front(); q.pop();
		if(u - 1 >= 0){
			if(d[u]+1 < d[u-1]){
				d[u-1] = d[u]+1;
				q.push(u-1);
			}
		}
		if(u + 1 < n){
			if(d[u]+1 < d[u+1]){
				d[u+1] = d[u]+1;
				q.push(u+1);
			}
		}
	}


	for(int i = 0; i < n; i++)
		printf("%d ", d[i]);
	printf("\n");



	return 0;
}