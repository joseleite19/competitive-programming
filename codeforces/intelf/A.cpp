#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n;
	string v[7];

	map<string, int> m;
	m["sunday"] = 0;
	m["monday"] = 1;
	m["tuesday"] = 2;
	m["wednesday"] = 3;
	m["thursday"] = 4;
	m["friday"] = 5;
	m["saturday"] = 6;
	
	v[0] = "sunday";
	v[1] = "monday";
	v[2] = "tuesday";
	v[3] = "wednesday";
	v[4] = "thursday";
	v[5] = "friday";
	v[6] = "saturday";

	vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	string a, b;

	cin >> a >> b;

	bool can = false;
	for(int i = 0; i < 12; i++){
		if(v[(m[a] + days[i])%7] == b)
			can = true;
	}
	if(can) cout << "YES" << endl;
	else cout << "NO" << endl;

	return 0;
}