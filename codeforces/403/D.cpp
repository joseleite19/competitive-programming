#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;

map<string, int> cnt;

char s[1003][30];
char c[1003];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf(" %s %c%*s", s[i], c+i);
		s[i][3] = 0;
	}

	bool bug = false;

	for(int w = 0; w < n; w++){
		for(int i = 0; i < n; i++) cnt[ s[i] ]++;
		
		for(int i = 0; i < n; i++){
			if(cnt[ s[i] ] == 1) continue;
			s[i][2] = c[i];
		}

		cnt.clear();
	}

	for(int i = 0; i < n; i++){
		if(cnt.count(s[i])) bug = true;
		cnt[ s[i] ]++;
	}

	if(!bug){
		printf("YES\n");
		for(int i = 0; i < n; i++)
			printf("%s\n", s[i]);
	}
	else{
		printf("NO\n");
	}

	return 0;
}