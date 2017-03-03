#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n;
int cnt1[1003];
int cnt2[1003];
int tmp[1003];

int used[10];
int config[10];


int bc(int i){
	if(i == n){

	}
	else{

	}
}

int main(){
	char c;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf(" %c", &c);
		// s[i] = c-'0';
		cnt1[c-'0']++;
	}

	for(int i = 0; i < n; i++){
		scanf(" %c", &c);
		// m[i] = c-'0';
		cnt2[c-'0']++;
	}

	for(int i = 0; i < 10; i++)
		tmp[i] = cnt2[i];

	int maxs = 0;

	for(int i = 0; i < 10; i++){
		if(!cnt1[i]) continue;
		int j = i+1;
		for(; j < 10; j++)
			if(tmp[j])
				break;
		if(j == 10) continue;
		for(int q = 0; q < cnt1[i]; q++){
			tmp[j]--;
			maxs++;

			if(!tmp[j]){
				while(j < 10 && !tmp[j]){
					j++;
				}
				if(j == 10) break;
			}
		}
	}

	for(int i = 0; i < 10; i++)
		tmp[i] = cnt2[i];


	int minm = 0;

	for(int i = 0; i < 10; i++){
		if(!cnt1[i]) continue;
		int j = i;
		for(; j < 10; j++)
			if(tmp[j])
				break;
		if(j == 10) continue;
		for(int q = 0; q < cnt1[i]; q++){
			tmp[j]--;
			minm++;

			if(!tmp[j]){
				while(j < 10 && !tmp[j]){
					j++;
				}
				if(j == 10) break;
			}
		}
	}

	printf("%d\n", n-minm);
	printf("%d\n", maxs);






	return 0;
}