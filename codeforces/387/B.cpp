#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
char s[1000];
int main(){

	scanf("%d %s", &n, s);
	int a, g, c, t;

	if(n % 4){
		printf("===\n");
		return 0;
	}

	a = g = c = t = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == 'A') a++;
		else if(s[i] == 'G') g++;
		else if(s[i] == 'C') c++;
		else if(s[i] == 'T') t++;
	}

	int qnt = n/4;

	if(a > qnt || g > qnt || c > qnt || t > qnt){
		printf("===\n");
		return 0;
	}

	for(int i = 0; i < n; i++){
		if(s[i] != '?') continue;
		if(a != qnt){
			a++;
			s[i] = 'A';
		}
		else if(g != qnt){
			g++;
			s[i] = 'G';
		}
		else if(c != qnt){
			c++;
			s[i] = 'C';
		}
		else if(t != qnt){
			t++;
			s[i] = 'T';
		}
	}

	printf("%s\n", s);

	return 0;
}