#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int f(int n){
	if(n == 0) return 6;
	if(n == 1) return 2;
	if(n == 2) return 5;
	if(n == 3) return 5;
	if(n == 4) return 4;
	if(n == 5) return 5;
	if(n == 6) return 6;
	if(n == 7) return 3;
	if(n == 8) return 7;
	if(n == 9) return 6;
}

void file(){
	freopen("alarm.in", "r", stdin);
	freopen("alarm.out", "w", stdout);
}

int main(){
	file();
	int n;

	map<int, pair<int, int> > ans;

	for(int i = 0; i < 24; i++){
		for(int j = 0; j < 60; j++){
			int x = f(i % 10) + f(i / 10) + f(j % 10) + f(j / 10);
			ans[x] = mp(i, j);
		}
	}

	scanf("%d", &n);

	if(ans.find(n) == ans.end()) printf("Impossible\n");
	else printf("%02d:%02d\n", ans[n].ff, ans[n].ss);

}