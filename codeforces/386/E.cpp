#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m, v[200005];

int add(int ptr, map<int, int> &mm){
	for(int i = ptr+2; i <= m; i += 2){
		if(mm.count(i)) continue;
		return i;
	}
	return 0;
}

int main(){

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int odd = 0, even = 0, ans = 0;

	map<int, int> o, e, mmo, mme;
	map<int, vector<int> > id;

	for(int i = 0; i < n; i++){
		id[ v[i] ].push_back(i);
		if(v[i] & 1){
			odd++;
			o[ v[i] ]++;
			if(v[i] <= m) mmo[ v[i] ] = 1;
		}
		else{
			even++;
			e[ v[i] ]++;
			if(v[i] <= m) mme[ v[i] ] = 1;
		}
	}

	set< pair<int, int> > so, se;

	for(map<int,int>::iterator it = o.begin(); it != o.end(); it++){
		so.insert(mp(it->ss, it->ff));
	}
	
	for(map<int,int>::iterator it = e.begin(); it != e.end(); it++){
		se.insert(mp(it->ss, it->ff));
	}
	
	int ptro =-1, ptre = 0;

	if(odd != even){

		while(odd > even){
			pair<int, int> tmp = *prev(so.end());
			so.erase(*prev(so.end()));

			ptre = add(ptre, mme);
			if(!ptre){ printf("-1\n"); return 0; }

			mme[ ptre ] = 1;

			int i = id[ tmp.ss ].back();
			v[i] = ptre;
			id[ tmp.ss ].pop_back();
			id[ ptre ].push_back(i);

			int sz = id[ v[i] ].size();
			se.erase(mp(sz-1, v[i]));
			se.insert(mp(sz, v[i]));

			tmp.ff--;
			if(tmp.ff) so.insert(tmp);
			else mmo.erase(tmp.ss);

			odd--; even++;
			ans++;
		}
		while(odd < even){
			pair<int, int> tmp = *prev(se.end());
			se.erase(*prev(se.end()));

			ptro = add(ptro, mmo);
			if(!ptro){ printf("-1\n"); return 0; }

			mmo[ ptro ] = 1;

			int i = id[ tmp.ss ].back();
			v[i] = ptro;
			id[ tmp.ss ].pop_back();
			id[ ptro ].push_back(i);

			int sz = id[ v[i] ].size();
			so.erase(mp(sz-1, v[i]));
			so.insert(mp(sz, v[i]));

			tmp.ff--;
			if(tmp.ff) se.insert(tmp);
			else mme.erase(tmp.ss);

			odd++; even--;
			ans++;
		}
	}


	while(prev(se.end())->ff != 1){
		pair<int, int> tmp = *prev(se.end());
		se.erase(*prev(se.end()));

		ptre = add(ptre, mme);
		if(!ptre){ printf("-1\n"); return 0; }

		mme[ptre] = 1;

		int i = id[ tmp.ss ].back();
		v[i] = ptre;
		id[ tmp.ss ].pop_back();
		id[ ptre ].push_back(i);

		tmp.ff--;
		se.insert(tmp);
		ans++;
	}
	
	while(prev(so.end())->ff != 1){
		pair<int, int> tmp = *prev(so.end());
		so.erase(*prev(so.end()));

		ptro = add(ptro, mmo);
		if(!ptro){ printf("-1\n"); return 0; }

		mmo[ptro] = 1;

		int i = id[ tmp.ss ].back();
		v[i] = ptro;
		id[ tmp.ss ].pop_back();
		id[ ptro ].push_back(i);

		tmp.ff--;
		so.insert(tmp);
		ans++;
	}
	
	printf("%d\n", ans);

	for(int i = 0; i < n; i++)
		printf(" %d", v[i]);
	printf("\n");

	return 0;
}