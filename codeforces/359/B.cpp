#include <bits/stdc++.h>

int main(){
	int n, v[105];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v + i);

	bool change = 0;
	
	do{
		change = false;
		for(int i = 0; i+1 < n; i++){
			if(v[i] > v[i+1]){
				printf("%d %d\n", i+1, i+2);
				std::swap(v[i], v[i+1]);
				change = true;
			}
		}
	}while(change);
}