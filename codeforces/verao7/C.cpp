#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;
char s[100005];
int n;

int main(){
	scanf("%s",s);
	n = strlen(s);
	int ans = 0,t = 1;
	int l = 0,r = n-1,lr = 0;
	while(1){
		// printf("%d %d %d %d\n",l,r,ans,lr);
		if(r < l) {
			t = max(t,ans);
			break;
		}
		if(s[l] == s[r]){
			if(l == r){
				t = max(t,ans+1);	
				break;
			} 
			else{
				if(!ans) lr = r - 1;
				ans += 2;
			// printf("..%d %d %d\n",l,r,ans);
				r--;
				l++;
			}
		}
		else{
			if(l > 0){
				l = 0;
				r = lr;
			}
			else r--;
			ans = 0;	
		} 
	}
	printf("%d\n",t);
	return 0;
}