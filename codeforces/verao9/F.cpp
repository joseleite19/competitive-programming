#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int dp[100005][2];
int n,v[100005];

int f(int x, int last){
	if(x == n) return 0;

	if(dp[x][v[x] == v[last]] != -1) return dp[x][v[x] == v[last]];

	if(abs(v[last] - v[x]) == 1){
		return dp[x][v[x] == v[last]] = f(x+1,last) + 1;
	}
	else{
		return dp[x][v[x] == v[last]] = min(f(x+1,last) + 1, f(x+1,x));
	}
}

int main(){

	scanf("%d",&n);
	for(int i = 0; i < n; i++) scanf("%d",v+i);
	
	memset(dp,-1,sizeof dp);
	
	printf("%d\n", f(0,0));



	return 0;
}