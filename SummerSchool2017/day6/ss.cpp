#include <bits/stdc++.h>

#define MOD1 1000000007
#define MOD2 1000000009
#define MOD3 1000000023

using namespace std;

char s[500005];
int v[500005];
int t[500005];
int nx[500005];
int n, m;
long long w1[500005];
long long w2[500005];
long long w3[500005];

int p[500005];

void pf(){

	for(int i = 2; i <= m; i++){
		p[i] = p[i-1];
		while(p[i] > 0 && v[ p[i] ] != v[i-1] && v[i-1] != -1 && v[p[i]] != -1) p[i] = p[ p[i] ];
		if(v[ p[i] ] == v[i-1] || v[ p[i] ] == -1 || v[i-1] == -1) p[i]++;
	}
	p[m+1] = 0;
}

int match(){
	int cnt = 0;

	int j = 0;
	for(int i = 0; i < n; i++){
		while(j > 0){
			if(t[i] == v[j] || (t[i] > j && v[j] == -1)) break;
			j = p[j];
		}
		if(t[i] == v[j] || (t[i] > j && v[j] == -1)) j++;

		if(j == m){
			j = p[j];
			cnt++;
		}
	}
	return cnt;
}


int main(){

	scanf("%s %d", s, &m);
	n = strlen(s);

	for(int i = 0; i < m; i++)
		scanf("%d", v+i);

	{
		map<char, int> mm;
		for(int i = 0; i < n; i++){
			if(mm.count(s[i])){
				int tmp = i - mm[ s[i] ];
				if(tmp < m){
					nx[ mm[ s[i] ] ] = i;
					t[i] = i - mm[ s[i] ];
				}
				else{
					t[i] = -1;
				}
			}
			else t[i] = -1;
			mm[ s[i] ] = i;
		}
	}
	{
		map<int, int> mm;
		for(int i = 0; i < m; i++){
			int old = v[i];
			if(mm.count(old))
				v[i] = i - mm[old];
			else v[i] = -1;
			mm[old] = i;
		}
	}

	// for(int i = 0; i < m; i++)
	// 	printf(" %d", v[i]);
	// printf("\n");

	pf();
	// for(int i = 1; i <= m; i++)
	// 	printf(" %d", p[i]);
	// printf("\n");

	// for(int i = 0; i < n; i++)
	// 	printf(" %d", t[i]);
	// printf("\n");

	printf("%d\n", match());





	return 0;
}