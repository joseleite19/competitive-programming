#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, v[100005];
	char s[100005];

	scanf("%d %s", &n, s);

	for(int i = 0; i < n; i++)
		scanf("%d", v + i);

	bool finite, over = false, used[100005];
	int actual = 0, next;

	memset(used, 0, sizeof used);

	while(!over){
		next = (s[actual] == '>') ? actual + v[actual] : actual - v[actual];
		if(next < 0 || next >= n){
			over = true;
			finite = true;
		}
		else if(used[next]){
			over = true;
			finite = false;
		}
		else{
			used[next] = true;
			actual = next;
		}
	}
	printf("%s\n", finite ? "FINITE" : "INFINITE");

	return 0;
}