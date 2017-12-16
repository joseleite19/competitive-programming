#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, k, v[200];

bool dead[200];

int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < k; i++)
		scanf("%d", v+i), v[i] %= (n-i);

	int person = 1;

	for(int i = 0; i < k; i++){
		int cnt = 0;
		while(dead[person]){
			person++;
			if(person == n+1) person = 1;
		}
		while(cnt < v[i]){
			person++;
			if(person == n+1) person = 1;
			if(!dead[person]){
				cnt++;
			}
		}
		dead[person] = 1;
		printf("%d ", person);
	}
	printf("\n");

	return 0;
}