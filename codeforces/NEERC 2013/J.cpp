#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int v[50005];

void print(int x){
	if(v[x] == -1){
		cout << x+1;
		return;
	}
	print(v[x]);
	cout << " " << x+1;
}

int main(){
	freopen("join.in", "r", stdin);
	freopen("join.out", "w", stdout);

	string s, handle, msg;
	int n;
	map<string, pair<int,int> > tab;
	pair<int,int> ans = {0,0};

	memset(v,-1,sizeof(v));
	cin >> n;
	getline(cin,s);
	for(int i = 0; i < n; i++){
		getline(cin,s);
		stringstream x(s);
		x >> handle; handle = handle.substr(0,handle.size()-1);
		
		int val = 1, id = i;
		v[id] = -1;
		while(x >> msg){
			if(msg[0] == '@' && handle != msg){
				if(tab.find(msg) != tab.end()){
					if(tab[msg].ff+1 > val){
						val = tab[msg].ff+1;
						v[id] = tab[msg].ss;
					}
				}
			}
		}
		if(val > ans.ff) ans = mp(val,id);
		if(tab.find(handle) == tab.end() || tab[handle].ff < val) tab[handle] = mp(val,id);
	}
	
	cout << ans.ff << "\n";
	print(ans.ss);
	cout << "\n";


	return 0;
}