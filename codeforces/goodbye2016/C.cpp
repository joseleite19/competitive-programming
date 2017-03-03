#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n;

	pair<int, int> v[200005];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d %d", &v[i].ff, &v[i].ss);

	int allone = 1;
	for(int i = 0; i < n; i++)
		if(v[i].ss == 2)
			allone = 0;

	if(allone){
		printf("Infinity\n");
		return 0;
	}

	int le, ri;

	if(v[0].ss == 1){
		le = 1000000000;
		ri = 1900;
	}
	else{
		le = 1900;
		ri = -1000000000;
	}

	for(int i = 0; i < n-1; i++){
		if(v[i+1].ss == 1){
			le += v[i].ff;
			ri = max(1900, ri+v[i].ff);
		}
		else{
			le = min(1900, le+v[i].ff);
			ri += v[i].ff;
		}

		if(le <= ri){
			printf("Impossible\n");
			return 0;
		}
	}
	le += v[n-1].ff;
	ri += v[n-1].ff;
	
	printf("%d\n", le-1);

	return 0;
}