#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, p[200];

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", p+i);
	getchar();

	bool equal = true;
	string s;
	for(int i = 0; i < n; i++){
		getline(cin, s);
		int cnt = 0;
		for(int j = 0; j < s.size(); j++){
			switch(s[j]){
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'y': cnt++;
				default:;
			}
		}
		if(cnt != p[i]) equal = false;
	}

	printf("%s\n", equal ? "YES" : "NO");

	return 0;
}