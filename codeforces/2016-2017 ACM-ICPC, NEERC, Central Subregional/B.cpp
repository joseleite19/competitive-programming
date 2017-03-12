#include <bits/stdc++.h>

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int a[3], cont = 0, final = 0;

int hanoi(int x, int y, int z, int n){
	if(n){
		hanoi(x, z, y, n-1);
		cont++;
		a[x]--;
		a[y]++;
		// if(!final)printf("%d Moving disc %d from %d to %d\n", cont, n, x, y);
		// if(!a[0] && !final) printf("|%d %d\n", 0, cont);
		// if(!a[1] && !final) printf("|%d %d\n", 1, cont);
		// if(!a[2] && !final) printf("|%d %d\n", 2, cont);
		if(a[0] == a[1] && a[1] == a[2] && !final)
			final = cont;
		hanoi(z, y, x, n-1);
	};
}

int main(){
	//file();
	int n;
	// scanf(" %d", &n);
	for(int i = 3; i <= 27; i += 3){
		cont = final = 0;
		n = i;
		a[0] = n;
		a[1] = a[2] = 0;
		hanoi(0, 1, 2, n);
		printf("%d %d\n", n, final);
		cont = 0;
		if(n % 2) cont = (1 << (n/3 - 1)) - 1;

		printf("%d %lld\n", n, (1LL << (2*n/3 - 1)) + (1 << (n/3 - 1)) -1 + cont); // PARA PAR
	}
	return 0;
}