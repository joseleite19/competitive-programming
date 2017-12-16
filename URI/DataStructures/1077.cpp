#include <bits/stdc++.h>

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)

using namespace std;

const int N = 3003;

char s[N];
int p[N];
int n;

inline bool op(char c){
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

inline int pre(char c){
	if(c == '+') return 0;
	if(c == '-') return 0;
	if(c == '*') return 1;
	if(c == '/') return 1;
	if(c == '^') return 2;
	assert(0);
}

void f(int L, int R){

	stack<char> ss;
	fore(i, L, R){
		if(s[i] == '('){
			f(i+1, p[i]-1), i = p[i];
			continue;
		}
		if(op(s[i])){
			while(!ss.empty() && pre(ss.top()) >= pre(s[i]))
				printf("%c", ss.top()), ss.pop();
			ss.push(s[i]);
		}
		else printf("%c", s[i]);
	}
	while(!ss.empty()) printf("%c", ss.top()), ss.pop();
}

int main(){

	int t;

	scanf("%d", &t);

	while(t--){
		scanf(" %s", s);
		n = strlen(s);
		{
			stack<int> ss;
			forn(i, n){
				if(s[i] == '(') ss.push(i);
				if(s[i] == ')') p[ ss.top() ] = i, ss.pop();
			}
		}

		f(0, n-1), printf("\n");
	}
}

