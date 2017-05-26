#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("king.in", "r", stdin);
	freopen("king.out", "w", stdout);
}

int d[200], m[200], y[200];

int main(){
	file();

	int n;
	int resp = -1;

	scanf("%d %d %d", &d[0], &m[0], &y[0]);

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &d[i], &m[i], &y[i]);

		int age = y[0] - y[i] - 1;

		if ((m[i] < m[0]) || (m[i] == m[0] && d[i] <= d[0])) {
			age++;
		}
		if (age >= 18) {
			//printf("%d %d\n", i, resp);
			//if (resp) {
			//	printf("%d %d %d\n", d[i], m[i], y[i]);
			//}
			if (resp == -1) {
				resp = i;
			} else if ((y[i] > y[resp]) ||
			(y[i] == y[resp] && m[i] > m[resp]) ||
			(y[i] == y[resp] && m[i] == m[resp] && d[i] > d[resp])) {
				resp = i;
			}
		}
	}

	printf("%d\n", resp);

	return 0;
}