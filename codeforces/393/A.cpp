#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){

	int m, d;

	scanf("%d %d", &m, &d);

	int ans = 0;

	ans++;
	int ss = 30;

	if(m == 2) ss = 28;
	else if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) ss = 31;

	ss -= 7 - d + 1;

	ans += ((ss + 6) / 7);

	printf("%d\n", ans);


	return 0;
}