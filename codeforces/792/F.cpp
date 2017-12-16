#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, v[200005];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	sort(v, v+n);

	int mn = 2000000000, cnt = 0;

	for(int i = 1; i < n; i++){
		int tmp = v[i] - v[i-1];
		if(tmp < mn){
			mn = tmp;
			cnt = 1;
		}
		else if(tmp == mn) cnt++;
	}

	printf("%d %d\n", mn, cnt);

	return 0;
}