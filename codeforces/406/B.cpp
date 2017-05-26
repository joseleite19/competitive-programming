#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n, m, k;

bool ans;

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		scanf("%d", &k);
		bool apper = false;
		set<int> s;
		int x;
		for(int j = 0; j < k; j++){
			scanf("%d", &x);
			if(s.count(-x)) apper = 1;
			s.insert(x);
		}
		if(!apper) ans = 1;
	}

	printf("%s\n", ans ? "YES" : "NO");
	

	return 0;
}