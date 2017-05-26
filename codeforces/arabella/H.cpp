#include <bits/stdc++.h>

using namespace std;

char s[1003];

int main(){
	int t, a, b;

	scanf("%d", &t);

	while(t--){
		scanf(" %s", s);
		string ss = s;
		reverse(ss.begin(), ss.end());
		bool can = true;
		for(int i = 0; s[i]; i++){
			switch(s[i]){
				case 'A' :
				case 'H' :
				case 'I' :
				case 'M' :
				case 'O' :
				case 'T' :
				case 'U' :
				case 'V' :
				case 'W' :
				case 'X' :
				case 'Y' : break;
				default: can = false; break;
			}
		}
		if(string(s) != ss) can = false;
		printf("%s\n", can ? "yes" : "no");
	}

	return 0;
}