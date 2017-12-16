#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)

using namespace std;

typedef long long ll;
const int N = 10000;

int main(){

	int n;

	scanf("%d", &n);

	string s;

	cin >> s;

	set <char> faltam;

	for(char i = 'a'; i <= 'z'; i++) faltam.insert(i);

	for(auto x: s) faltam.erase(x);

	int m;

	scanf("%d", &m);

	vector <int> letras(26,0);

	int total = m;

	for(int i = 0; i < m; i++){

		string nova;
		cin >> nova;

		bool valido = true;

		for(int j = 0; j < s.size(); j++){
			if(s[j] == '*' and faltam.find(nova[j]) == faltam.end()) valido = false;
			if(s[j] != '*' and s[j] != nova[j]) valido = false;
		}

		if(!valido) total--;
		else{

			set <char> inserido;

			for(int j = 0; j < s.size(); j++){
				if(s[j] == '*' and inserido.find(nova[j]) == inserido.end()){
					letras[nova[j] - 'a']++;
					inserido.insert(nova[j]);
				}
			}
		}
	}

	int resp = 0;

	for(int i = 0; i < 26; i++){
		if(letras[i] == total) resp++;
	}

	printf("%d\n",resp);

	return 0;
}

