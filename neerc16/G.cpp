#include <bits/stdc++.h>

using namespace std;

set<int> s[102];
int cnt[102];
int main(){
	int n;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		cnt[i] = n;
		s[i].insert(i);
	}

	int ptr = 1;
	cnt[1]--;
	printf("1 1 0\n");
	while(1){
		int px = -1;
		for(int i = 1; i <= n; i++){
			if(i == ptr) continue;
			if(cnt[i] >= 2 && !s[ptr].count(i)){
				px = i;
				break;
			}
		}
		if(px == -1) break;
		printf("%d %d %d\n", px, px, ptr);
		cnt[px]--;
		s[ptr].insert(px);
		ptr = px;
	}
	printf("0 1 %d\n", ptr);

	return 0;
}