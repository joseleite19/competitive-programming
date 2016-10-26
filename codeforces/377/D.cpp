#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, m, d[100005], a[100005], qnt[100005];

	vector<int> antes[100005];

	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++)
		scanf("%d", d+i);
	
	for(int i = 0; i < m; i++)
		scanf("%d", a+i);

	set<int> s;
	for(int i = 0; i < n; i++){
		antes[ d[i] ].push_back(i);
		if(d[i]) s.insert(i);
	}

	set<int> s2 = s;

	int tot = s.top();

	for(int i = 0; i < m; i++){
		int tmp = antes[i].size();
		tmp = antes[i][tmp-1];
		qnt[i] = a[i];

	}


	

	return 0;
}