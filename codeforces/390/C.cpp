#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m, pr[102];

string name[102];
string text[102];

vector<vector<int> > g;

int main(){

	char sss[102];
	char ttt[102];
	int t;
	string s;

	scanf("%d", &t);

	while(t--){
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf(" %s", sss);
			name[i] = sss;
		}

		scanf("%d", &m);
		g.assign(m, vector<int>());

		for(int i = 0; i < m; i++){
			scanf(" %s:%[^\n]", sss, ttt);
			text[i] = ttt;
			s = sss;
			if(s != '?'){
				
			}
		}


	}



	return 0;
}