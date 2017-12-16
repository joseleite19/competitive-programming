#include <bits/stdc++.h>

using namespace std;

char qwe[50], asd[50];

int main(){
	int n, t;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);
		map<string, set<string> > m;
		string s, q;

		for(int i = 0; i < n; i++){
			scanf(" %s %s", qwe, asd);
			m[asd].insert(qwe);
		}

		long long ans = 1;
		for(auto & e : m)
			ans *= (long long)( e.second.size()) + 1;
		ans--;

		printf("%lld\n", ans);
	}



	return 0;
}