#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("black.in", "r", stdin);
	freopen("black.out", "w", stdout);
}

int main(){
	file();
	int b, w, c, d;

	int mat[101010][2];

	scanf("%d %d", &b, &w);

	d = c = 0;
	for(int i = 0; i < 2*(b+w+1); i++){
		if(i & 1){
			mat[i][0] = mat[i][1] = '@';
			c++;	
		}
		else{
			mat[i][0] = mat[i][1] = '.';
			d++;
		}
	}

	int next = 2;

	while(c > b){
		mat[next][1] = '@';
		next += 2;
		c--;
	}
	next = 1;
	while(d > w){
		mat[next][0] = '.';
		next += 2;
		d--;
	}

	printf("%d 2\n", 2*(b+w+1));

	for(int i = 0; i < 2*(b+w+1); i++)
		printf("%c%c\n", mat[i][0], mat[i][1]);

	return 0;
}