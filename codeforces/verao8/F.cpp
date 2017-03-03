#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int n, f, v[10000], t[10000];
int main(){
	file();


	scanf("%d %d", &n, &f);

	int dir = 0;

	for(int i = 0; i < n; i++){
		scanf("%d", v+i);
		t[ v[i] ] = 1;
	}

	// 1 = up; 2 = down
	if(v[0] >= f) dir = 1;
	else dir = 2;


	for(int i = 0; i < n; i++){
		if(t[ v[i] ] == 0) continue;

		if(f < v[i]){
			while(f <= v[i]){
				if(t[f]){
					t[f] = 0;
					printf("%d ", f);
					// break;
				}
				f++;
			}
		}
		else{
			while(f >= v[i]){
				if(t[f]){
					t[f] = 0;
					printf("%d ", f);
					// break;
				}
				f--;
			}
		}
		f = v[i];
	}
	printf("\n");

	return 0;
}