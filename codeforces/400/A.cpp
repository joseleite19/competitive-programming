#include <bits/stdc++.h>

using namespace std;

char s[50], t[50];

int main(){
	string a, b;
	map<string, string> m;

	scanf(" %s", s);
	a = s;
	scanf(" %s", s);
	b = s;

	int n;

	scanf("%d", &n);

	printf("%s %s\n", a.c_str(), b.c_str());
	for(int i = 0; i < n; i++){
		scanf(" %s %s", s, t);
		string aa = s, bb = t;
		if(aa == a) a = bb;
		else b = bb;
		
		printf("%s %s\n", a.c_str(), b.c_str());
	}

	// while(1){
	// 	printf("%s %s\n", a.c_str(), b.c_str());
	// 	if(m.count(a)) a = m[a];
	// 	else if(m.count(b)) b = m[b];
	// 	else break;
	// }






	return 0;
}