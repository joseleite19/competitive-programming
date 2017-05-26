#include <bits/stdc++.h>

#define ss second
#define ff first
#define mp make_pair
#define oo 100000000

using namespace std;

int main(){

	int n,m;

	scanf("%d %d", &n, &m);

	vector <string> v;

	for(int i = 0; i < n; i++){
		string str;
		cin >> str;
		v.push_back(str);
	}

	vector <int> opr;

	string resp;

	vector <bool> foi(n,false);

	for(int i = 0; i < m; i++){
		int val;
		scanf("%d", &val);
		val--;
		foi[val] = true;
		if(i == 0) resp = v[val];
		opr.push_back(val);
	}

	bool da = true;

	for(int i = 1; i < opr.size(); i++){
		if(resp.size() != v[opr[i]].size()){
			da = false;
			break;
		}

		for(int j = 0; j < resp.size(); j++){
			if(resp[j] == '?') continue;
			if(resp[j] != v[opr[i]][j]){
				resp[j] = '?';
			}
		}
	}

	if(da == false){
		printf("No\n");
		return 0;
	}

	for(int i = 0; i < v.size(); i++){
		if(v[i].size() != resp.size()) continue;
		if(foi[i]) continue;

		bool compativel = true;

		for(int j = 0; j < resp.size(); j++){
			if(resp[j] == '?') continue;
			if(resp[j] != v[i][j]) compativel = false;
		}
		if(compativel){
			da = false;
			break;
		}
	}

	if(da == false){
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
	cout << resp << endl;
}