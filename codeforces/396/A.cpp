#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

char s[100005], t[100005];

int main(){

	scanf(" %s %s", t, s);

	if(strcmp(s, t) == 0){
		printf("-1\n");
		return 0;
	}

	int s1 = strlen(s), s2 = strlen(t);

	if(s1 > s2){
		printf("%d\n", s1);
	}
	else if(s1 < s2){
		printf("%d\n", s2);
	}
	else{
		printf("%d\n", s2);
	}

	return 0;
}