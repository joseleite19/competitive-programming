#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;


int main(){
	int n;
	char s[200];

	scanf("%d %s", &n, s);

	int cnt = 0, flag = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == 'B'){
			if(!flag) cnt++;
			flag = 1;
		}
		else flag = 0;
	}

	printf("%d\n", cnt);
	if(!cnt) return 0;

	int f = 0;
	cnt = 0;
	for(int i = 0; i < n; i++){
		if(s[i] == 'B'){
			cnt++;
		}
		else{
			if(cnt){
				printf("%s%d", f ? " ": "", cnt);
				f = 1;
			}
			cnt = 0;
			flag = 0;
		}
	}
	if(cnt) printf("%s%d", f ? " ": "", cnt);
	printf("\n");


	return 0;
}