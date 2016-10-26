#include <bits/stdc++.h>

#define ss second
#define ff first
#define mp make_pair

using namespace std;

int qnt[2005], q[2005];
int v[2005];
vector<int> id[2005];
int main(){
	int n, m;

	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", v+i);
		int tmp = v[i];
		if(v[i] > m) tmp = 0;
		qnt[ tmp ]++;
		id[ tmp ].push_back(i);
	}

	if(n == 1){
		printf("1 %d\n", v[0] > m);
		printf("%d\n", v[0] <= m ? v[0] : 1);
		return 0;
	}

	set< pair<int, int> > s;

	for(int i = 1; i <= m; i++)
		s.insert(mp(qnt[i], i));
	
	while(qnt[0] > 0){
		vector<pair<int, int> > aux;
		aux.push_back(*s.begin());
		s.erase(s.begin());

		while(s.size() > 0 && s.size() < m && aux[0].ff == s.begin()->ff){
			aux.push_back(*s.begin());
			s.erase(s.begin());
		}
		if(qnt[0] >= (int)aux.size()){
			for(int i = 0; i < (int)aux.size(); i++){
				int a = id[0][ id[0].size()-1 ];
				id[0].pop_back();
				qnt[0]--;
				aux[i].ff++;
				id[aux[i].ss].push_back(a);
			}
		}
		else qnt[0] = 0;
		for(int i = 0; i < (int)aux.size(); i++)
			s.insert(aux[i]);
	}

	while(1){
		vector<pair<int, int> > aux;
		aux.push_back(*s.begin());
		s.erase(s.begin());
		if(s.size() == 0){
			s.insert(aux[0]);
			break;
		}
		while(s.size() > 1 && aux[0].ff == s.begin()->ff){
			aux.push_back(*s.begin());
			s.erase(s.begin());
		}
		pair<int,int> tmp = *prev(s.end());
		s.erase(prev(s.end()));
			// printf("asd %d %d %d\n", tmp.ff - (int)aux.size() , aux[0].ff, tmp.ff - (int)aux.size() > aux[0].ff);
		
		if(tmp.ff - (int)aux.size() > aux[0].ff){
			for(int i = 0; i < aux.size(); i++){
				// printf("### %d\n", aux[i].ss);
				int a = id[tmp.ss][ id[tmp.ss].size()-1 ];
				id[tmp.ss].pop_back();
				tmp.ff--;
				aux[i].ff++;
				id[aux[i].ss].push_back(a);
				s.insert(aux[i]);
			}
			s.insert(tmp);
		}
		else{
			printf("##%d %d %d##\n", (int)id[0].size(), (int)aux.size(), aux[0].ff);
			if(id[0].size() >= aux.size()){
				for(int i = 0; i < aux.size(); i++){
					int a = id[0][ id[0].size()-1 ];
					id[0].pop_back();
					aux[i].ff++;
					id[aux[i].ss].push_back(a);
					s.insert(aux[i]);
				}
				s.insert(tmp);
			}
			else{
				for(int i = 0; i < aux.size(); i++){
					s.insert(aux[i]);
					// printf("%d %d#\n", aux[i].ff, aux[i].ss);
				}
				s.insert(tmp);

				break;
			}
		}
	}


	while((int)id[0].size() > 0){
		vector<pair<int, int> > aux;
		aux.push_back(*s.begin());
		s.erase(s.begin());

		while(s.size() > 0 && s.size() < m && aux[0].ff == s.begin()->ff){
			aux.push_back(*s.begin());
			s.erase(s.begin());
		}
		if(qnt[0] >= (int)aux.size()){
			for(int i = 0; i < (int)aux.size(); i++){
				int a = id[0][ id[0].size()-1 ];
				id[0].pop_back();
				qnt[0]--;
				aux[i].ff++;
				id[aux[i].ss].push_back(a);
				s.insert(aux[i]);
			}
		}
		else break;
		for(int i = 0; i < (int)aux.size(); i++)
			s.insert(aux[i]);
	}

	int aa = 1e9;
	for(int i = 1; i <= m; i++){
		aa = min(aa, (int)id[i].size());
		for(int j = 0; j < id[i].size(); j++){
			q[id[i][j]] = i;
		}
	}
	for(int i = 0; i < n; i++)
		if(!q[i]) q[i] = v[i];

	int ans1 = aa, ans2 = 0;

	for(int i = 0; i < n; i++){
		if(v[i] != q[i]) ans2++;
	}
	
	printf("%d %d\n%d", ans1, ans2, q[0]);
	for(int i = 1; i < n; i++)
		printf(" %d", q[i]);
	printf("\n");

	return 0;
}