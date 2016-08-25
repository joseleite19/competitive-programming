#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("fraud.in", "r", stdin);
	freopen("fraud.out", "w", stdout);

	vector<int> v;
	string s[1001], start;
	int n;

	cin >> start >> n;
	for(int i = 0; i < n; i++){
		cin >> s[i];
		bool match = true;
		for(int j = 0; s[i][j]; j++){
			if(start[j] == '*') continue;
			if(start[j] != s[i][j]) match = false;
		}
		if(match) v.push_back(i);
	}
	printf("%d\n", (int)v.size());
	for(int i = 0; i < (int)v.size(); i++)
		printf("%s\n", s[ v[i] ].c_str());


	return 0;
}