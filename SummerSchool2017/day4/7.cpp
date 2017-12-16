#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

char s[50004];
int main(){
	int n;

	scanf("%d", &n);

	set<string> ss;
	bool ok = true;
	string sss[102];
	for(int i = 0; i < n; i++){
		scanf(" %s", s);
		sss[i] = s;
		// if(ss.insert(sss).ss)
		// 	ok = false;
	}

	for(int i = 0; i < n; i++){
		// for(int j = i; j < n;)
	}

	printf("%s\n", ok ? "YES" : "NO");

	return 0;
}