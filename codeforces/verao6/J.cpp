#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main(){
	file();
	int n, a, b;
	char s[1000];

	scanf("%d %d %d %s", &n, &a, &b, s);

	int cnt0 = 0, cnt1 = 0, cnt2;

	for(int i = 0; i < n; i++){
		if(s[i] == '0') cnt0++;
		if(s[i] == '1') cnt1++;
		if(s[i] == '2') cnt2++;
	}

	if(a + b > n){
		printf("-1\n");
		return 0;
	}

	int ans = 0;
	if(cnt0 > a && cnt1 < b){
		for(int i = 0; i < n && cnt0 > a && cnt1 < b; i++){
			if(s[i] == '0'){
				s[i] = '1';
				cnt0--;
				cnt1++;
				ans++;
			}
		}
	}

	if(cnt0 < a && cnt1 > b){
		for(int i = 0; i < n && cnt0 < a && cnt1 > b; i++){
			if(s[i] == '1'){
				s[i] = '0';
				cnt1--;
				cnt0++;
				ans++;
			}
		}
	}

	if(cnt0 < a){
		for(int i = 0; i < n && cnt0 < a; i++){
			if(s[i] == '2'){
				s[i] = '0';
				cnt0++;
				ans++;
			}
		}
	}
	
	if(cnt1 < b){
		for(int i = 0; i < n && cnt1 < b; i++){
			if(s[i] == '2'){
				s[i] = '1';
				cnt1++;
				ans++;
			}
		}
	}

	if(cnt0 > a){
		for(int i = 0; i < n && cnt0 > a; i++){
			if(s[i] == '0'){
				s[i] = '2';
				cnt0--;
				ans++;
			}
		}
	}
	if(cnt1 > b){
		for(int i = 0; i < n && cnt1 > b; i++){
			if(s[i] == '1'){
				s[i] = '2';
				cnt1--;
				ans++;
			}
		}
	}

	printf("%d\n%s\n", ans, s);

	return 0;
}