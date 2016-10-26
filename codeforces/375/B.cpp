#include <bits/stdc++.h>


using namespace std;

int main(){
	int n;
	char s[300];

	scanf("%d %s", &n, s);

	int lengout = 0, qntin = 0;

	bool p = 0;
	int tmp = 0;
	s[n++] = '_';
	for(int i = 0; i < n; i++){
		if(s[i] == '('){
			p = 1;
			lengout = max(lengout, tmp);
			tmp = 0;
		}
		else if(s[i] == ')'){
			p = 0;
			if(tmp) qntin++;
			tmp = 0;
		}
		else if(s[i] == '_'){
			if(!p) lengout = max(lengout, tmp);
			if(tmp && p) qntin++;
			tmp = 0;
		}
		else tmp++;
	}
	printf("%d %d\n", lengout, qntin);

	return 0;
}