#include <bits/stdc++.h>

using namespace std;

char s[2003], s2[2003];

string ss;

int n;
void putpos(char c, int pos){
	// printf("%c %d\n", c, pos);
	for(int i = 0; i < n; i++){
		if(s2[i]) continue;
		if(!pos){
			s2[i] = c;

			return;
		}
		pos--;
	}
}

int main(){

	scanf("%d %s", &n, s);

	for(int i = 0; i < n; i++){
		int pos = (n-i)/2;
		if((n-i)%2 == 0) pos--;
		putpos(s[i], pos);
	}
	s2[n] = 0;


	printf("%s\n", s2);

	return 0;
}