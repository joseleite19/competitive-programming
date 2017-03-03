#include <bits/stdc++.h>

using namespace std;

int main(){
	set<string> ss;
	char s[100];
	string tmp;

	scanf("%s", s);
	tmp = s;

	ss.insert(tmp);
	int n = tmp.size();

	for(int i = 0; i < n; i++){
		tmp = tmp.substr(1) + tmp[0];
		ss.insert(tmp);
	}

	printf("%d\n", (int)ss.size());
}