#include <bits/stdc++.h>

using namespace std;

int p[26][26];

int main(){
	char nick[1000006];

	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			scanf("%d", &p[i][j]);

	for(int i = 0; i < 26; i++)
		p[i][i] = 0;

	for(int i = 0; i < 26; i++)
		for(int j = 0; j < 26; j++)
			for(int k = 0; k < 26; k++)
				p[j][k] = min(p[j][k], p[j][i] + p[i][k]);

	scanf("%s", nick);

	int size = strlen(nick);

	long long sum = 0;
	for(int i = 0; i < size / 2; i++){
		long long tmp = 1e18;
		int a = nick[i]-'a', b = nick[size-i-1]-'a';
		for(int j = 0; j < 26; j++) tmp = min(tmp, (long long)p[a][j] + p[b][j]);
		sum += tmp;
	}

	printf("%lld\n", sum);

	return 0;
}