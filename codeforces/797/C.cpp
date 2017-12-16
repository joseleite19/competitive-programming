#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
char s[100005];

vector<int> v[26];

int main(){

	scanf("%s", s);
	n = strlen(s);

	string ans = "";
	stack<char> st;

	for(int i = 0; i < n; i++){
		v[ s[i]-'a' ].push_back(i);
	}

	for(int i = 0; i < n; i++){
		st.push(s[i]);
		
		while(!st.empty()){
			bool has = 0;
			for(int j = 0; j < st.top()-'a'; j++){
				int id = upper_bound(v[j].begin(), v[j].end(), i) - v[j].begin();
				if(id == v[j].size()) continue;
				has = 1;
			}
			if(has) break;
			ans += st.top();
			st.pop();
		}
	}

	while(!st.empty()) ans += st.top(), st.pop();

	printf("%s\n", ans.c_str());

	return 0;
}