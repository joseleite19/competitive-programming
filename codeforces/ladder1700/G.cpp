#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

set<int> ans;

set<int> g[100];

void b(set<int> r, set<int> p, set<int> x){
	if(p.empty() && x.empty()){
		if(r.size() > ans.size())
			ans = r;
	}
	while(!p.empty()){
		int u = *p.begin(); p.erase(p.begin());

		set<int> np, nx, nr;
		for(int v : g[u]){
			if(p.count(v)) np.insert(v);
			if(x.count(v)) nx.insert(v);
		}
		nr = r;
		nr.insert(u);
		b(nr, np, nx);
		x.insert(u);
	}
}

pair<string, string> v[50];

int getnum(char *s, int &i){
	int ans = 0;
	int sig = 1;
	while(s[i] && !(s[i] >= '0' && s[i] <= '9')){
		if(s[i] == '-') sig = -1;
		i++;
	}
	while(s[i] && s[i] >= '0' && s[i] <= '9'){
		ans = 10*ans + (s[i]-'0');
		i++;
	}
	return sig * ans;
}

int main(){

	char matr[50], nome[50], viz[50];
	int x;

	FILE *fp = fopen("amigos_tag20171.txt", "r");
	if(!fp) return printf("Cant read file.\n"), 0;

	istringstream is("-1");
	int n = 1;
	for(int i = 1; fscanf(fp, " %s | %[^|] | %[^\n]", matr, nome, viz) == 3; i++, n++){
		v[i] = make_pair(matr, nome);
		int id = 0;
		while(1){
			x = getnum(viz, id);
			if(!x) break;
			if(x == -1) break;
			g[i].insert(x);
			g[x].insert(i);
		}
	}

	set<int> init;
	for(int i = 1; i <= n; i++) init.insert(i);

	b(set<int>(), init, set<int>());

	for(int x : ans){
		printf("%d %s %s\n", x, v[x].first.c_str(), v[x].second.c_str());
	}



	return 0;
}