#include <bits/stdc++.h>

int main(){
	char s[100005];

	scanf("%s", s);
	int i;
	for(i = 0; s[i]; i++)
		printf("%c", s[i]);
	for(i--; i >= 0; i--)
		printf("%c", s[i]);
	printf("\n");
}