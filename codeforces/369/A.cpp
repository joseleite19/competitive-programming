#include <bits/stdc++.h>

using namespace std;

int main(){
	char s[1005][10];
	int n;
	bool can = false;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf(" %s", s[i]);
		if(!can){
			if(s[i][0] == 'O' && s[i][1] == 'O'){
				can = true;
				s[i][0] = s[i][1] = '+';
			}
			else if(s[i][3] == 'O' && s[i][4] == 'O'){
				can = true;
				s[i][3] = s[i][4] = '+';
			}
		}
	}

	if(!can) printf("NO\n");
	else{
		printf("YES\n");
		for(int i = 0; i < n; i++)
			printf("%s\n", s[i]);
	}

	return 0;
}