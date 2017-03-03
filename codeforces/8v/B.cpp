#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n, m;

	scanf("%d %d", &n, &m);

	int r = 0;

	char s[1000];
	string sss;

	set<string> ss;

	for(int i = 0; i < n; i++){
		scanf(" %s", s);
		ss.insert(s);
	}

	for(int i = 0; i < m; i++){
		scanf(" %s", s);
		if(ss.count(s))
			r++;
	}

	n -= r;
	m -= r;

	if(r & 1) n++;

	printf("%s\n", n > m ? "YES" : "NO");


	return 0;
}