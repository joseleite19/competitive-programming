#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m;
char s[1003], t[1003]

int main(){

	scanf(" %s %s", s, t);
	n = strlen(s);

	map<char, char> k;

	for(int i = 0; i < n; i++){
		if(s[i] != t[i]){
			if(k.count(s[i])){
				if(k[ s[i] ] != t[i]){
					printf("-1\n");
					return 0;
				}
			}
			else{
				k[ s[i] ] = t[i];
				k[ t[i] ] = s[i];
			}
		}
	}

	printf("%d\n", (int)k.size());
	for(map<char, char>::iterator it = k.begin(); it != k.end(); it++)
		printf("%c %c\n", it->ff, it->ss);




	return 0;
}