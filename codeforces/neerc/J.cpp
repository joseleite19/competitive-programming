#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

struct coisa{
	long long a, x, y;
};

void file(){
	freopen("joy.in", "r", stdin);
	freopen("joy.out", "w", stdout);
}

coisa v[100005];

int main(){
	file();
	long long sx,sy,fx,fy,vmax,n,k;

	scanf("%lld%lld%lld%lld", &sx,&sy,&fx,&fy);
	scanf("%lld%lld%lld", &n,&k,&vmax);

	for(long long i = 0; i < n; i++){
		scanf("%lld%lld%lld", &v[i].a, &v[i].x, &v[i].y);
	}

	long long x = sx, y = sy;
	long long prox;
	for(long long i = 0; i < n; i++){
		if(i == n-1) prox = k;
		else prox = v[i+1].a;
		x += (prox-v[i].a)*v[i].x;
		y += (prox-v[i].a)*v[i].y;
	}

	double dist = hypot((x-fx), (y-fy));

	if(dist/vmax > k){
		printf("No\n");
		return 0;
	}

	printf("Yes\n");

	double xx = ((double)fx-x)/k, yy = ((double)fy-y)/k;

	double a = sx, b = sy;
	long long j = 0;
	for(long long i = 0; i < k; i++){
		if (j != n -1 && i == v[j + 1].a) {
			j++;
		}
		a += v[j].x + xx;
		b += v[j].y + yy;

		printf("%.15lf %.15lf\n", a,b);
	}

	return 0;
}