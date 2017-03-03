#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;


int ptr;
// string all[1000006];

map<int, vector<string> > m;

char s[1000006];
int n;
int f(int lv){
	int n = 0;
	char c;

	while(1){
		scanf(" %c", &c);
		if(c == ',') break;
		s[n++] = c;
	}
	s[n] = 0;
	scanf("%d,", &n);
	string ss = s;
	int tmp = n;
	m[lv].push_back(ss);

	for(int i = 0; i < n; i++)
		f(lv+1);
}


int main(){

	int lv = 0;

	while(!feof(stdin))
		f(0);

	printf("%d\n", (int)m.size());

	for(map<int, vector<string> >::iterator it = m.begin(); it != m.end(); it++){
		vector<string> &v = it->second;
		for(int i = 0; i < (int)v.size(); i++)
			printf("%s ", v[i].c_str());
		printf("\n");
	}

	return 0;
}