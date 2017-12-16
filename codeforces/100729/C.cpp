#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int last[100050];
int ft[3000050];

int n, m;

void update(int i, int v) {
	for (; i <= m + n; i += (i & -i)) ft[i] += v;
}
int query(int i) {
	int resp = 0;
	for (; i; i -= (i & -i)) resp += ft[i];
	return resp;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= m + n; i++) {
				ft[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			last[i] = n - i + 1;
			update(last[i], 1);
		}
		for (int i = 0; i < m; i++) {
			int a;

			scanf("%d", &a);

			printf("%d ", query(i + n) - query(last[a]));

			update(last[a], -1);
			last[a] = i + n + 1;
			update(last[a], 1);
		}
		printf("\n");

	}

	return 0;
}