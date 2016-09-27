#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;
int n, v[100005];

int count(){
	int r = 0, b = 0;

	for(int i = 0; i < n; i++){
		if(i & 1){
			if(v[i] == 0){
				r++;
			}
		}
		else{
			if(v[i] == 1){
				b++;
			}
		}
	}
	if(!r && !b) return 0;

	int ret = r + b - min(r, b);
	return ret;
}

int main(){
	char c;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf(" %c", &c);
		v[i] = (c == 'r');
	}

	int ans = count();

	for(int i = 0; i < n; i++)
		v[i] ^= 1;

	ans = min(ans, count());

	printf("%d\n", ans);

	return 0;
}