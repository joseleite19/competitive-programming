#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int l[100], r[100];
int q[100];

int p[100];
int check[256];

pair <int, int> swi[100050];

int nn = 0;

int que[200];
int bb = 0;

void file(){
	freopen("instruction.in", "r", stdin);
	freopen("instruction.out", "w", stdout);
}

int main(){
	file();
	int n;

	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		char a;
		int pa;

		scanf(" %c %d", &a, &pa);

		if (a == 'p') {
			char b;
			scanf(" %c", &b);

			check[(int) b] = i;
		} else {
			//
		}
		p[i] = pa;
		if (l[pa]) {
			r[pa] = i;
		} else {
			l[pa] = i;
		}
	}

	int m;

	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		int ini;
		char a;
		bb = 0;

		scanf(" %d %c", &ini, &a);

		int fim = check[(int) a];

		while (fim) {
			que[bb++] = fim;
			//printf("f %d\n", fim);
			fim = p[fim];
		}
		//printf("\n");
		ini++;

		int ima = que[--bb];
		int mirai;
		
		while (bb) {
			mirai = que[--bb];

//			printf("i %d %d\n", ima, mirai);

			if (mirai == l[ima]) {
				if (q[ima]) {
					swi[nn].ss = ima;
					swi[nn++].ff = ini;
					q[ima] = 0;
				}
			} else {
				if (!q[ima]) {
					swi[nn].ss = ima;
					swi[nn++].ff = ini;
					q[ima] = 1;
				}
			}
			ima = mirai;
			ini++;
		}
	}
	sort(swi, swi + nn);

	printf("%d\n", nn);
	for (int i = 0; i < nn; i++) {
		printf("%d %d\n", swi[i].ss, swi[i].ff);
	}

}