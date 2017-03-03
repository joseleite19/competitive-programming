#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, m;
char s[1003], t[1003];

int main(){

	scanf(" %s %s", s, t);
	n = strlen(s);

	map<char, char> k;

	for(int i = 0; i < n; i++){
		char c, r;
		c = s[i];
		r = t[i];

		if(k.count(r)){
			if(k[ r ] != c){
				printf("-1\n");
				return 0;
			}
		}
		else if(k.count(c)){
			if(k[c] != r){
				printf("-1\n");
				return 0;
			}
		}
		else{
			k[r] = c;
			k[c] = r;
		}
	}

	set<pair<char, char> > sss;

	for(map<char, char>::iterator it = k.begin(); it != k.end(); it++){
		pair<char, char> mmm = mp(it->ff, it->ss);
		if(mmm.ff > mmm.ss) swap(mmm.ff, mmm.ss);
		if(mmm.ff != mmm.ss) sss.insert(mmm);
	}

	printf("%d\n", (int)sss.size());
	for(set<pair<char, char> >::iterator it = sss.begin(); it != sss.end(); it++)
		printf("%c %c\n", it->ff, it->ss);
	




	return 0;
}