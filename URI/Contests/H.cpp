#include <bits/stdc++.h>

using namespace std;
int oc[26], favorite[26];

int count(){
	int ans = 0;
	for(int i = 0; i < 26; i++)
		if(favorite[i])
			ans += oc[i];
	return ans;
}

int main(){
	int k, m, n;
	char aux[27];
	char name[100005], a[100005], b[100005];

	scanf("%d %d %d %s %s", &k, &m, &n, aux, name);
	memset(favorite, 0, sizeof favorite);
	for(int i = 0; i < k; i++)
		favorite[ aux[i]-'a' ] = 1;

	memset(oc, 0, sizeof oc);

	for(int i = 0; i < m; i++)
		oc[ name[i]-'a' ]++;


	int maximum = count();
	int id = -1;
	for(int i = 0; i < n; i++){
		scanf(" %c %c", a + i, b + i);

		int tmp = oc[ a[i]-'a' ];
		oc[ a[i]-'a' ] = oc[ b[i]-'a' ];
		oc[ b[i]-'a' ] = tmp;
		if(count() > maximum){
			maximum = count();
			id = i;
		}
		// printf("%d\n", count());
	}

	char show[26];
	for(int i = 0; i < 26; i++)
		show[i] = 'a' + i;

	for(int i = 0; i <= id; i++){
		int j, id1, id2;
		for(j = 0; j < 26; j++){
			if(show[j] == a[i]) id1 = j;
			if(show[j] == b[i]) id2 = j;
		}

		show[ id1 ] = b[i];
		show[ id2 ] = a[i];
	}

	printf("%d\n", maximum);
	for(int i = 0; i < m; i++)
		printf("%c", show[ name[i]-'a' ]);
	printf("\n");

	return 0;
}