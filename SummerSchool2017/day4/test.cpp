#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
}

int main(){
	file();
	
	char v[] = {'(', '[', '{', '<', '}', '>', ')', ']'};

	srand(time(0));
	int n = 1000000;
	printf("1\n");
	//for(int i = 0; i < n; i++){
		printf("%c", v[rand()%4]);
		for(int i = 1; i < n; i++)
			printf("%c", v[rand()%8]);
		printf("\n");
	//}

	return 0;
}