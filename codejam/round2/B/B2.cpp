#include <bits/stdc++.h>

using namespace std;

int n, m, c;
int main(){

	int t;

	scanf("%d", &t);

	for(int tc = 1; tc <= t; tc++){

		scanf("%d %d %d", &n, &c, &m);
		multiset<int> s1, s2;
		int a, b;
		for(int i = 0; i < m; i++){
			scanf("%d %d", &a, &b);
			if(b == 2) s1.insert(a);
			if(b == 1) s2.insert(a);
		}
		if(s1.size() < s2.size()) swap(s1, s2);
		int ans = s1.size();
		// int ans = 0;
		int tmp = 0;
		for(int c : s1){
			if(s2.size() == 0) break;
			multiset<int>::iterator it = s2.begin();
			for(; it != s2.end(); it++){
				if(*it != c) break;
			}
			// printf("%d\n", s2.size());
			if(it == s2.end()){
				if(c != 1){
					if(s2.size()){
						s2.erase(s2.find(c));
						tmp++;
					}
				}
				// else ans++;
			}
			else s2.erase(it);
			// if(s2.count(c)){
			// 	if(c == 1) ans++;
			// 	else tmp++;
			// 	s2.erase(s2.find(c));
			// }
		}
		ans += s2.size();

		printf("Case #%d: %d %d\n", tc, ans, tmp);
	}


	return 0;
}