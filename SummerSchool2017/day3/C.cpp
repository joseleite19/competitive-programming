#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

set<int> s[102];

int main(){

	for(int k = 1; k <= 100; k++){
		for(int j = 0; j <= k; j++){
			int tmp = (j*1000/k);
			if(tmp % 10 >= 5) tmp = tmp/10 + 1;
			else tmp = tmp / 10;
			s[k].insert(tmp);
		}
	}

	int n, v[20];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int ans = 1;

	while(1){
		int cnt = true;
		for(int i = 0; i < n; i++){
			if(!s[ans].count(v[i])){
				cnt = false;
				break;
			}
		}
		if(cnt) break;
		ans++;
	}

	printf("%d\n", ans);


	return 0;
}