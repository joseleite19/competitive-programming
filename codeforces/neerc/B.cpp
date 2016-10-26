#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("buffcraft.in", "r", stdin);
	freopen("buffcraft.out", "w", stdout);
}

int b, k, cd, cp;
pair<int,int> d[50004], p[50004];

int main(){
	file();

	scanf("%d %d %d %d", &b, &k, &cd, &cp);

	for(int i = 0; i < cd; i++){
		scanf("%d", &d[i].ff);
		d[i].ss = i+1;
	}

	for(int i = 0; i < cp; i++){
		scanf("%d", &p[i].ff);
		p[i].ss = i+1;
	}

	sort(d, d+cd, greater<pair<int,int> >());
	sort(p, p+cp, greater<pair<int,int> >());

	cd = min(cd, k);
	cp = min(cp, k);
	// while(cp > 0 && p[cp-1].ff == 0) cp--;

	long long ans = b, porc = 100;
	int last = cd;
	for(int i = 0; i < cd; i++){
		ans += d[i].ff;
	}

	int ptr = 0;
	for(int i = 0; i < k - cd && i < cp; i++){
		porc += p[i].ff;
		ptr++;
	}
	long long tmp1 = ans * porc;

	pair<int, int> maxi = mp(cd-1, ptr-1);

	last = cd;
	for(int w = 0; w < k; w++){
		last--;
		if(last < 0) break;
		if(ptr == cp) break;

		ans -= d[last].ff;

		porc += p[ptr].ff;

		if(ans * porc > tmp1){
			tmp1 = ans * porc;
			maxi = mp(last-1, ptr);
		}

		ptr++;
	}
	printf("%d %d\n", maxi.ff+1, maxi.ss+1);
	
	if(maxi.ff >= 0){
		printf("%d", d[0].ss);
		for(int i = 1; i <= maxi.ff; i++){
			printf(" %d", d[i].ss);
		}
		printf("\n");
	}
	if(maxi.ss >= 0){
		printf("%d", p[0].ss);
		for(int i = 1; i <= maxi.ss; i++){
			printf(" %d", p[i].ss);
		}
		printf("\n");
	}
}