#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

char s[200];
char ans[200];
int main(){
	int n, i, j, end = 0;
	
	scanf("%d %s", &n, s);

	for(j = 0; j < n; ){
		// printf("%d\n", j);
		bool bit = 1;
		bool flag = 1;
		int cnt = 0;
		int old = j;
		for(; j < n; j++){
			if(bit && s[j] == 'o') bit = 0, cnt++;
			else if(!bit && s[j] == 'g') bit = 1, cnt++;
			else break;
		}
		if(cnt >= 3){
			ans[end++] = ans[end++] = ans[end++] = '*';
			if(cnt % 2 == 0) j--;
		}
		else{
			if(j == n){
				while(old < j) ans[end++] = s[old++];
			}
			else if(old == j){
				while(old <= j) ans[end++] = s[old++];
				j++;
			}
			else while(old < j) ans[end++] = s[old++];
		}
		// if(old == j) j++;
	}

	ans[end++] = '\0';

	printf("%s\n", ans);


	return 0;
}