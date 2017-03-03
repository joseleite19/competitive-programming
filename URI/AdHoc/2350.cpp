#include <bits/stdc++.h>

using namespace std;


int T[500005], P[500005], pos[500005], n, m;

int prepoc(){
	int x = -1;

	pos[0] = x;
	for(int i = 1; i < m; i++){
		while(x >= 0 && P[x+1] != P[i])
			x = pos[x];
		if(P[x+1] == P[i])
			x++;
		pos[i] = x;
	}
}

int kmp(){
	int x = -1;
	int ans = 0;

	for(int i = 0; i < n; i++){
		int c = T[i];
		printf("%d %d %d\n", i, x, T[i]);

		while(x >= 0){
			c = T[i];
			if(c != -1 && i - x > c) c = -1;
			if(P[x+1] == c) break;
			x = pos[x];
		}

		c = T[i];
		if(c != -1 && i - x > c) c = -1;

		if(P[x+1] == c){
			x++;
			if(x == m-1){
			printf("##%d\n", i);
				ans++;
				if(T[i] - x - 1 < 0){
					x--;
					while(x >= 0 && P[x+1] != -1)
						x = pos[x];
					// if(P[x+1] == -1)
					// 	x++;
				}
				else x = pos[x];
			}
		}
	}
	return ans;
}

char s[500005];
int main(){
	int x;

	scanf("%s %d", s, &m);

	n = strlen(s);

	map<int, int> last;

	for(int i = 0; i < n; i++){
		x = s[i];
		if(last.count(x)) T[i] = i - last[x];
		else T[i] = -1;
		last[x] = i;
	}

	last.clear();

	for(int i = 0; i < m; i++){
		scanf("%d", &x);
		if(last.count(x)) P[i] = i - last[x];
		else P[i] = -1;
		last[x] = i;
		// printf(".%d\n", P[i]);
	}

	prepoc();
	// for(int i = 0; i < m; i++)
	// 	printf("..%d\n", pos[i]);
	
	int ans = kmp();

	printf("%d\n", ans);

	return 0;
}