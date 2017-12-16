#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i < b; i++)

using namespace std;

const int N = 5005;

int n, v[N];

int f(int i, int j){
	if(i == j) return 1;

}

int main(){

	scanf("%d", &n);

	forn(i, n) scanf("%d", v+i);

	int ans = 0;
	while(1){
		int ok = 1;
		for(int i = 0; i < n; i++){
			if(!v[i]) continue;
			ok = 0;
			int j = i, mn = v[i];
			while(j < n && v[j]) mn = min(mn, v[j++]);
			printf("%d %d\n", i, j);
			for(int w = i; w < j; w++) v[w] -= mn;
			ans++;
			i = j-1;
		}
		if(ok) break;
	}
	printf("%d\n", ans);


}
