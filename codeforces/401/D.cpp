#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n;
string s[500000];
char ss[500001];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf(" #%s", ss);
		s[i] = ss;
	}

	for(int i = n-2; i >= 0; i--){
		string news = "";
		int j = 0;
		for(j = 0; j < s[i].size() && j < s[i+1].size(); j++){
			if(s[i][j] != s[i+1][j])
				break;
			news += s[i][j];
		}

		if(j == s[i].size()){
			continue;
		}
		else if(j == s[i+1].size()){
			s[i] = s[i+1];
		}
		else{
			if(s[i][j] < s[i+1][j]) continue;
			else{
				s[i] = news;
			}
		}
	}

	for(int i = 0; i < n; i++)
		printf("#%s\n", s[i].c_str());


	return 0;
}