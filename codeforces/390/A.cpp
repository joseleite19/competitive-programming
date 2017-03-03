#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, v[200];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int sum = 0, last = 1;
	bool allzero = true;

	for(int i = 0; i < n; i++)
		if(v[i])
			allzero = false;


	if(allzero){
		printf("NO\n");
		return 0;
	}

	printf("YES\n");

	vector<pair<int, int> > vv;

	for(int i = 0; i < n; i++){
		if(v[i]){
			vv.push_back(mp(v[i], i+1));
		}
	}
	printf("%d\n", (int)vv.size());
	if(vv.size() == 1) printf("1 %d\n", n);
	else{
		printf("1 %d\n", vv[0].ss);
		for(int i = 1; i < (int)vv.size()-1; i++){
			printf("%d %d\n", vv[i-1].ss+1, vv[i].ss);
		}
		printf("%d %d\n", vv[vv.size()-1].ss, n);
	}

	return 0;
}