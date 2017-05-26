#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n;
	char s[30];

	scanf("%d", &n);

	long long ans = 0;
	for(int i = 0; i < n; i++){
		scanf(" %s", s);
		if(!strcmp(s, "Tetrahedron")) ans += 4;
		if(!strcmp(s, "Cube")) ans += 6;
		if(!strcmp(s, "Octahedron")) ans += 8;
		if(!strcmp(s, "Dodecahedron")) ans += 12	;
		if(!strcmp(s, "Icosahedron")) ans += 20;
	}
	printf("%lld\n", ans);



	return 0;
}