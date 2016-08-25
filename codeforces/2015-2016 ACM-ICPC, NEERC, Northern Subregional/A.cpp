#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("alex.in", "r", stdin);
	freopen("alex.out", "w", stdout);
}

int main(){
	file();

	int h, w;

	scanf("%d %d", &h, &w);

	if(h < w) swap(h, w);

	printf("%.4lf\n", max(min(h/3.0, w*1.0), w/2.0));

	return 0;
}