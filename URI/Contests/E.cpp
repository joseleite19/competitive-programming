#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	string s;

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		cin >> s;
		if(i) printf(" ");
		if(s.size() == 3){
			if(s[0] == 'O' && s[1] == 'B') printf("OBI");
			else if(s[0] == 'U' && s[1] == 'R') printf("URI");
			else cout << s;
		}
		else cout << s;
	}
	cout << endl;

	return 0;
}