#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;
int ft[100];

int a, b, c, d;
int f(int i, int j, int k, int q){
	int tmp = 0, last = 0;

	if(a >= i) last++;
	if(b >= i) last++;
	if(c >= i) last++;
	if(d >= i) last++;

	tmp += last;

	// printf("..%d\n", tmp);

	if(i+1 == j) tmp += last;
	else{
		last = 0;

		if(a >= j) last++;
		if(b >= j) last++;
		if(c >= j) last++;
		if(d >= j) last++;
		last++;
		tmp += last;
	}

	if(j+1 == k) tmp += last;
	else{
		last = 0;
		if(a >= k) last++;
		if(b >= k) last++;
		if(c >= k) last++;
		if(d >= k) last++;
		last += 2;
		tmp += last;
	}

	if(k+1 == q) tmp += last;
	else{
		last = 0;
		if(a >= q) last++;
		if(b >= q) last++;
		if(c >= q) last++;
		if(d >= q) last++;
		last += 3;
		tmp += last;
	}
	return tmp;
}


int main(){
	// a = 2, b = 3, c = 20, d = 21;
	// printf("%d\n", f(1, 2, 3, 5));

	scanf("%d %d %d %d", &a, &b, &c, &d);

	for(int i = a; i < 60; i += (i & -i))
		ft[i]++;
	for(int i = b; i < 60; i += (i & -i))
		ft[i]++;
	for(int i = c; i < 60; i += (i & -i))
		ft[i]++;
	for(int i = d; i < 60; i += (i & -i))
		ft[i]++;


	pair<int, pair<int, pair<int, int> > > ans;
	int tmp = 0;

	for(int i = 1; i <= 49; i++){
		for(int j = i+1; j <= 50; j++){
			for(int k = j+1; k <= 51; k++){
				for(int q = k+1; q <= 52; q++){
					int t = f(i, j, k, q);
					if(t > tmp){
						ans = mp(i, mp(j, mp(k, q)));
						tmp = t;
					}
				}
			}
		}
	}

	// printf("%d\n", tmp);
	printf("%d %d %d %d\n", ans.ff, ans.ss.ff, ans.ss.ss.ff, ans.ss.ss.ss);


	return 0;
}