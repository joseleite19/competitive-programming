#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

char s[100005];
int main(){
	
	scanf(" %s", s);

	int n = strlen(s);

	// Bulbasaur
	map<char, int> m;

	m['B'] = 0;
	m['u'] = 0;
	m['l'] = 0;
	m['b'] = 0;
	m['a'] = 0;
	m['s'] = 0;
	m['a'] = 0;
	m['u'] = 0;
	m['r'] = 0;
	int cnt = 0, ptr = 0;
	for(int i = 0; i < n; i++){
		// if(s[i] == m[ptr]) ptr++;
		// if(ptr == 9){
		// 	cnt++;
		// 	ptr = 0;
		// }
		if(m.count(s[i]))
			m[ s[i] ]++;
	}

	cnt = min(m['B'],min(m['u']/2,min(m['l'],
		min(m['b'],min(m['a']/2,min(m['s'],min(m['a'],min(m['u'],m['r']))))))));
	printf("%d\n", cnt);



	return 0;
}