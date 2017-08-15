#include <bits/stdc++.h>

using namespace std;

int main(){

	int n,k,r;

	scanf("%d %d %d", &n, &k, &r);

	bool vis[n];

	memset(vis,false, sizeof(vis));

	while(k--){
		int pos;
		scanf("%d", &pos);
		pos--;
		vis[pos] = true;
	}

	int L = 0;

	int R = r-1;

	int cont = 0;

	for(int i = 0; i <= r-1; i++){
		if(vis[i]) cont++;
	}

	int resp = 0;

	if(cont < 2){
		for(int i = r-1; i >= 0; i--){
			if(vis[i] == false){
				vis[i] = true;
				cont++;
				resp++;
			}

			if(cont == 2) break;
		}
	}

	while(R < n){

		R++;
		if(vis[L]) cont--;
		if(vis[R]) cont++;

		L++;

		if(cont == 0){
			vis[R] = true;
			vis[R-1] = true;
			resp += 2;
			cont = 2;
		}
		else if(cont == 1){
			if(vis[R] == false) vis[R] = true;
			else vis[R-1] = true;
			resp++;
			cont = 2;
		}
	}

	printf("%d\n",resp	 );


	return 0;
}