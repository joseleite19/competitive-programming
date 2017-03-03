#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, q;

int when[102];

int get(int t, int k, int d){
	int sum = 0;

	for(int i = 0; i < n; i++){
		if(when[i] <= t){
			sum++;
		}
	}

	if(sum < k) return -1;
	
	int ret = 0;
	for(int i = 0; i < n && k > 0; i++){
		if(when[i] <= t){
			ret += i+1;
			when[i] = t+d;
			k--;
		}
	}
	return ret;
}

int main(){
	int t, k, d;

	scanf("%d %d", &n, &q);

	while(q--){
		scanf("%d %d %d", &t, &k, &d);
		int tmp = get(t, k, d);
		printf("%d\n", tmp);
	}

	return 0;
}