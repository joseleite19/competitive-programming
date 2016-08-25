#include <bits/stdc++.h>

#define oo 100000000
#define ff first
#define ss second

using namespace std;

int main(){
	int m, c, a, b, n;

	scanf("%d", &n);

	m = c = 0;
	while(n--){
		scanf("%d %d", &a, &b);
		if(a > b) m++;
		if(b > a) c++;
	}

	if(m > c) printf("Mishka\n");
	else if(m < c) printf("Chris\n");
	else printf("Friendship is magic!^^\n");

	return 0;
}