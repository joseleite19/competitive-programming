#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int vis[100005];
int n;

int main(){

	int ans = 0, cnt = 0, x;

	scanf("%d", &n);

	for(int i = 0; i < 2*n; i++){
		scanf("%d", &x);
		if(vis[x]){
			cnt--;
		}
		else{
			vis[x] = 1;
			cnt++;
			ans = max(ans, cnt);
		}
	}

	printf("%d\n", ans);
	



	return 0;
}