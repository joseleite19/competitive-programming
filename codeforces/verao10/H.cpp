#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define oo 1000000

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}


int u, n, v[1003];

int main(){

	scanf("%d", &u);

	for(int tc = 1; tc <= u; tc++){
		scanf("%d", &n);

		for(int i = 0; i < n; i++)
			scanf("%d", v+i);

		bool who = true;
		int last = -1;

		for(int i = 0; i < n; i++){
			if(v[i] != last){
				last = v[i];
				who ^= 1;
			}
		}
		printf("%s\n", n & 1 ? "TAK" : "NIE");
	}

	return 0;
}