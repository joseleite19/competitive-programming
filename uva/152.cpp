#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

double dist(pair<int,int> a, pair<int,int> b){
	return hypot(a.ff - b.ff, a.ss - b.ss);
}

double dist(pair<pair<int,int>, int> a, pair<pair<int,int>, int> b){
	return hypot(dist(a.ff, b.ff), a.ss - b.ss);
}

int v[10];

int main(){
	int a, b, c;
	vector<pair<pair<int,int>, int> > p;

	while(scanf("%d %d %d", &a, &b, &c) == 3 && a+b+c)
		p.push_back(mp(mp(a, b), c));

	for(int i = 0; i < p.size(); i++){
		double d = 1e50;
		for(int j = 0; j < p.size(); j++){
			if(i == j) continue;
			d = min(d, dist(p[i], p[j]));
		}
		int tmp = (int)(d);
		if(tmp > 9) continue;
		// printf("%lf\n", d);
		v[tmp]++;
	}
	for(int i = 0; i < 10; i++)
		printf("%4d", v[i]);
	printf("\n");

	return 0;
}