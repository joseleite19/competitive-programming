#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main(){
	file();
	map<int, int> m;
	int n, k;

	scanf("%d %d", &n, &k);

	int x;

	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		m[x]++;
	}

	bool ok = true;
	for(map<int, int>::iterator it = m.begin(); it != m.end(); it++){
		if(it->ss % k)
			ok = false;
	}

	printf("%s\n", ok ? "OK" : "ARGH!!1");

	return 0;
}