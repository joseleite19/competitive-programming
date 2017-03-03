#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

struct coisa{
	int x, y, v, type;
	coisa(){}
	coisa(int x, int y, int v, int type) : x(x), y(y), v(v), type(type) {}
};


struct coisa2{
	int v, type;
	double ang;
	coisa2(){}
	coisa2(int ang, int v, int type) : ang(ang), v(v), type(type) {}
	bool operator<(const coisa2 & o) const{
		ang < o.ang;
	}
};

double pi = acos(-1);

int main(){
	int p, l;

	coisa point[2003];
	coisa2 event[8003];
	int a, b, c, n;

	while(scanf("%d %d", &p, &l) == 2){
		for(int i = 0; i < p; i++){
			scanf("%d %d %d", &a, &b, &c);
			point[i] = coisa(a, b, c, 1);
		}
		
		for(int i = 0; i < l; i++){
			scanf("%d %d %d", &a, &b, &c);
			point[p+i] = coisa(a, b, c, 2);
		}

		n = p+l;

		for(int i = 0; i < n; i++){
			int k = 0;
			for(int j = 0; j < n; j++){
				if(j == i) continue;
				double dx = point[j].x - point[i].x;
				double dy = point[j].y - point[i].y;
				double ang = atan(dy/dx);

				event[k++] = coisa2(ang, point[j].v, point[j].type);
				event[k++] = coisa2(ang+pi, -point[j].v, point[j].type);
			}
			sort(event, event+k);

		}
		

	}



	return 0;
}