#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
}

int main(){
	file();
	
	char s[1010];

	scanf(" %s", s);

	for(int i = 0; s[i]; i++){
		printf("%c", s[i]);
		if(s[i] == '-'){
			int x;
			for(x = i+1; s[x+1] && s[x+1] != '-' && s[x+1] != '+'; x++);
			int last = x;
			for(int j = x; j > i+1; j--) if(s[j] != '0') last = j;
			
			for(int j = i+1; j < last; j++){
				printf("%c", s[j]);
				if(j+1 < last) printf("+");
			}
			if(last != i+1) printf("+");
			for(i = last; i <= x; i++) printf("%c", s[i]);
			i--;
		}
	}
	printf("\n");

	return 0;
}