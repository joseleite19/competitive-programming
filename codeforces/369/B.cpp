#include <bits/stdc++.h>

using namespace std;

int main(){
	set<long long> p1, p2;

	int n, mat[505][505];

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf(" %d", &mat[i][j]);
		}
	}

	long long tmp = 0;
	bool haszero = false;
	for(int i = 0; i < n; i++){
		tmp = 0;
		haszero = false;
		for(int j = 0; j < n; j++){
			tmp += mat[i][j];
			if(!mat[i][j]) haszero = true;
		}
		if(!haszero) p1.insert(tmp);
		else p2.insert(tmp);
	}
	
	for(int j = 0; j < n; j++){
		tmp = 0;
		haszero = false;
		for(int i = 0; i < n; i++){
			tmp += mat[i][j];
			if(!mat[i][j]) haszero = true;
		}
		if(!haszero) p1.insert(tmp);
		else p2.insert(tmp);
	}

	tmp = 0;
	haszero = false;
	for(int i = 0; i < n; i++){
		tmp += mat[i][i];
		if(!mat[i][i]) haszero = true;
	}
	if(!haszero) p1.insert(tmp);
	else p2.insert(tmp);
	
	tmp = 0;
	haszero = false;
	for(int i = 0; i < n; i++){
		tmp += mat[i][n-1-i];
		if(!mat[i][n-1-i]) haszero = true;
	}
	if(!haszero) p1.insert(tmp);
	else p2.insert(tmp);

	if(n == 1){
		printf("1\n");
	}
	else if(p1.size() != 1 || p2.size() != 1){
		printf("-1\n");
	}
	else{
		long long ans = (*p1.begin() - *p2.begin());
		printf("%lld\n", ans > 0 ? ans : -1);
	}

	return 0;
}
