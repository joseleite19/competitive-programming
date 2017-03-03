#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

int n;
char s[200005];
int lef[200005];
int rig[200005];
int main(){

	scanf("%d %s", &n, s);

	for(int i = 0; i < n; i++)
		lef[i] = i-1, rig[i] = i+1;

	rig[n-1] = 0;
	lef[0] = n-1;

	int d, r;
	d = r = 0;

	int tamd, tamr;
	tamd = tamr = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == 'D') tamd++;
		else tamr++;
	}

	int i = 0;
	while(tamr && tamd){
		if(s[i] == 'R' && r){
			rig[ lef[i] ] = rig[i];
			lef[ rig[i] ] = lef[i];
			r--;
			tamr--;
		}
		else if(s[i] == 'D' && d){
			rig[ lef[i] ] = rig[i];
			lef[ rig[i] ] = lef[i];

			tamd--;
			d--;
		}
		else if(s[i] == 'R'){
			d++;
		}
		else if(s[i] == 'D'){
			r++;
		}


		i = rig[i];
	}

	printf("%c\n", tamd ? 'D' : 'R');

	return 0;
}