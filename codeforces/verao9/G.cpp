#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
}

int n;

char s[400];

int main(){

	scanf("%d", &n);


	for(int i = 0; i < n; i++){
		scanf(" %s", s);
		int sz = strlen(s);

		if((s[sz-2] == 'c' && s[sz-1] == 'h') || s[sz-1] == 'x' || s[sz-1] == 's' || s[sz-1] == 'o'){
			printf("%ses\n", s);
		}
		else if(s[sz-2] == 'f' && s[sz-1] == 'e'){
			s[sz-2] = 'v';
			printf("%ss\n", s);
		}
		else if(s[sz-1] == 'f'){
			s[sz-1] = 'v';
			printf("%ses\n", s);
		}
		else if(s[sz-1] == 'y'){
			s[sz-1] = 'i';
			printf("%ses\n", s);
		}
		else printf("%ss\n", s);
 	}




	return 0;
}