#include <bits/stdc++.h>

using namespace std;


int main(){
	char s[100005];
	int n;
	bool letters[26];
	memset(letters, 0, sizeof letters);
	
	scanf("%d %s", &n, s);

	if(n > 26){
		printf("-1\n");
		return 0;
	}
	int count = 0;
	for(int i = 0; i < n; i++){
		if(letters[s[i]-'a']){
			count++;
		}
		letters[s[i]-'a'] = true;
	}
	printf("%d\n", count);




	return 0;
}