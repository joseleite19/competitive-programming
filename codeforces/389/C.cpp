#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
char s[200005];

int main(){

	scanf("%d %s", &n, s);

	int ans = 1;
	int h, v;

	h = v = -1;

	for(int i = 0; i < n; i++){
		if(s[i] == 'R'){
			if(h == -1){
				h = 1;
			}
			else if(h == 0){
				v = -1;
				h = 1;
				ans++;
			}
		}
		if(s[i] == 'L'){
			if(h == -1){
				h = 0;
			}
			else if(h == 1){
				v = -1;
				h = 0;
				ans++;
			}
		}
		if(s[i] == 'D'){
			if(v == -1){
				v = 0;
			}
			else if(v == 1){
				h = -1;
				v = 0;
				ans++;
			}
		}
		if(s[i] == 'U'){
			if(v == -1){
				v = 1;
			}
			else if(v == 0){
				h = -1;
				v = 1;
				ans++;
			}
		}
	}

	printf("%d\n", ans);


	return 0;
}