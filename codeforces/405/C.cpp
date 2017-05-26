#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define MOD (1000000007)
#define oo (1000000000000000000)

using namespace std;

int n, k;

int v[100];

char ans[55][20];

int ptr = 1;
string f(int x, bool low = false){
	char c = 'A';
	if(low) c = 'a';
	string ret = "";
	c += (x-1);
	ret = c;

	if(x <= 26) return ret;

	return 'A' + f(x - 26, 1);
}

int tmp[100];

int p[100];

int fd(int x){
	return x == p[x] ? x : p[x] = fd(p[x]);
}

int main(){
	for(int i = 0; i < 100; i++) p[i] = i;

	scanf("%d %d", &n, &k);

	{
		char s[10];
		for(int i = 1; i <= n-k+1; i++){
			scanf(" %s", s);
			if(!strcmp(s, "YES")) v[i] = 1;
			else v[i] = 0;
		}
	}

	int allno = 1;
	for(int i = 1; i <= n-k+1; i++){
		if(!v[i]){
			p[ fd(i) ] = fd(i+k-1);
		}
		else allno = 0;
	}

	if(allno){
		for(int i = 0; i < n; i++)
			printf("%s ", f(1).c_str());
		printf("\n");

		return 0;
	}


	// for(int i = 0; i < n-k+1; i++){
	// 	if(!v[i]) continue;
	// 	int j = i;
	// 	while(j < n-k+1 && v[j]) j++;
	// 	j--;

	// 	for(int q = i; q < j+k; q++){
	// 		if(!tmp[q]){
	// 			tmp[q] = ptr++;
	// 		}
	// 	}

	// 	i = j;
	// }

	// for(int i = 0; i < n; i++){
	// 	if(!tmp[i]) continue;
	// 	for(int j = i-k; j >= 0 && !tmp[j]; j -= k)
	// 		tmp[j] = tmp[i];
	// 	for(int j = i+k; j < n && !tmp[j]; j += k)
	// 		tmp[j] = tmp[i];
	// }

	// for(int i = 0; i < n; i++)
	// 	if(!tmp[i])
	// 		tmp[i] = ptr;


	{
		for(int i = 1; i <= n-k+1; i++){
			set<int> ss;
			for(int j = i; j < i+k; j++)
				ss.insert(fd(j));
			int x = (ss.size() == k);
			if(x != v[i]){

				// printf("%d\n", i);
			}
		}
	}

	for(int i = 1; i <= n; i++)
		printf("%s ", f(fd(i)).c_str());
	printf("\n");




	return 0;
}