#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, x;
	pair<int,int> v[10];

	for(int tc = 1; scanf("%d", &n) == 1; tc++){
		for(int i = 0; i < 10; i++){
			scanf("%*d.%d", &v[i].ff);
			v[i].ss = i;
		}

		sort(v, v+10, [](const pair<int,int> &a, const pair<int,int> & b){
			if(a.ff != b.ff) return a.ff > b.ff;
			return a.ss < b.ss;
		});

		printf("Caso %d: ", tc);
		for(int i = 0; i < n; i++)
			printf("%d", v[i].ss);
		printf("\n");
	}

}