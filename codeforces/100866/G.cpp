/* Gravila's Rap */

#include <bits/stdc++.h>

using namespace std;

int main(){
	int K, n;
	char text[17000005];
	string word;
	map<string, string> dictionary;

	scanf("%d", &K);

	for(int i = 0; i < K; i++){
		string a, b;
		cin >> a >> b;
		dictionary[a] = b;
	}

	n = 0;
	while(cin >> word && word != "END"){
		string s = dictionary[word];
		for(int i = 0; s[i]; i++)
			text[n++] = s[i];
	}

	vector<int> pi(n);
	pi[0] = 0;
	for(int i = 1; i < n; i++){
		int j = pi[i-1];
		while(j > 0 && text[i] != text[j])
			j = pi[j-1];
		if(text[i] == text[j]) pi[i] = j+1;
		else pi[i] = 0;
	}

	int k = n - pi[n-1];
	printf("%d\n", n % k ? n : k);

	return 0;
}