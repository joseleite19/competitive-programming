#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int t,a,b;

	scanf("%d", &t);

	while(t--){
		scanf("%d/%d", &a, &b);
		while(a != 1 || b != 1){
			if(a > b){
				printf("R");
				a-=b;
				swap(a,b);
			}
			else{
				printf("L");
				swap(a,b);
				a-=b;
			}
		}
		printf("\n");
	}

	return 0;
}