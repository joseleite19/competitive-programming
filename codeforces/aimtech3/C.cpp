#include <bits/stdc++.h>


char volta(char c){
	return 'a' +  (c-'a' - 1 + 26) % 26;
}

int main(){
	char s[100005];

	scanf("%s", s);

	int start = 0;

	for(start = 0; s[start]; start++)
		if(s[start] > 'a')
			break;

	if(!s[start]){
		start--;
		s[start] = volta(s[start]);

		printf("%s\n", s);

		return 0;
	}

	while(s[start] && volta(s[start]) < s[start])
		s[start] = volta(s[start]), start++;

	printf("%s\n", s);


	return 0;
}