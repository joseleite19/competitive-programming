#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

int n,k[2],v[2][7003];
int dp[2][7003];
int mark[2][7003];
int pa[2][7005];

int f(int ta, int j){
   
    if(ta == n-1)	return 2;
    if(pa[j][ta] > 0) dp[j][ta] = max(dp[j][ta],1);

    for(int i = 0; i < k[j];){
   		i = pa[j][ta];
   		pa[j][ta]++;
    	dp[j][ta] = max(f((ta + v[j][i]) % n, !j),dp[j][ta]);
    }
    
    if(dp[j][ta] == 2)
        return 0;
    if(dp[j][ta] == 0)
        return 2;
    return dp[j][ta];
}

int main(){
    scanf("%d",&n);
    scanf("%d",&k[0]);
    for(int i = 0; i < k[0]; i++){
        scanf("%d",&v[0][i]);
    }
    scanf("%d",&k[1]);
    for(int i = 0; i < k[1]; i++){
        scanf("%d",&v[1][i]);
    }
    for(int i = 0; i < n - 1; i++){
        int r = f(i,0);
        printf("%d\n",dp[1][1] );
        printf("%s ", r == 0 ? "Win" : r == 1 ? "Loop" : "Lose");
    }
    printf("\n");
    for(int i = 0; i < n - 1; i++){
        int r = f(i,1);
        printf("%s ", r == 0 ? "Win" : r == 1 ? "Loop" : "Lose");
    }
        printf("\n");
return 0;
}