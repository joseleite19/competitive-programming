#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n;
	char s[100005];

	scanf("%d %s", &n, s);

	int a = 0, b = 0;

	for(int i = 0; i < strlen(s); i++)
		if(s[i] == 'A') a++;
		else b++;

	if(a == b) printf("Friendship\n");
	else if(a > b) printf("Anton\n");
	else printf("Danik\n");


	return 0;
}