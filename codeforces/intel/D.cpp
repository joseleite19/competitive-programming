#include <bits/stdc++.h>

int main(){
	int n, x;
	set<int> s;
	set<int>::iterator it;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		s.insert(x);
	}
	
	while(1){
		it = prev(s.end());
		x = *it;

		while(x && s.find(x) != s.end()) x >>= 1;

		if(!x) break;

		s.erase(it);
		s.insert(x);
	}
	
	it = s.begin();
	printf("%d", *it);
	for(it++; it != s.end(); it++){
		printf(" %d", *it);
	}
	printf("\n");

	return 0;
}