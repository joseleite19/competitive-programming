#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){

	int a = 0, b = 0;

	int d, r, t;

	scanf("%d %d %d", &d, &r, &t);

	b = 3;
	a = 4;

	int e = 5;

	for(int i = 1; i < d; i++){
		a += e;
		e++;
	}

	int f = 4;

	while(a+b != r+t){
		a += e;
		b += f;
		e++, f++;
	}

	printf("%d\n", r - a);



	return 0;
}