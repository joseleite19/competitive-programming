#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

#define mp make_pair
#define ff first
#define ss second
#define EP 1e-5

using namespace std;

struct tipo_reta{
	double x1,y1,x2,y2;
	tipo_reta(){}
	tipo_reta(double a, double b, double c, double d){
		x1 = a; y1 = b; x2 = c; y2 = d;
	}
};

double dist(pair<double,double> a, pair<double,double> b){
	double aux = a.ff-b.ff; aux*= aux;
	double aux2 = a.ss-b.ss; aux2*=aux2;
	return sqrt(aux+aux2);
}

double Dot(pair<double,double> a, pair<double,double> b){
	return a.ff*b.ff+a.ss*b.ss;
}

double cross(pair<double,double> a, pair<double,double> b){
	return a.ff*b.ss-a.ss*b.ff;
}

double dist_line(pair<double,double> p, pair<double,double> a, pair<double,double> b){
	pair<double,double> u,v,w,z;
	u = {b.ff-a.ff,b.ss-a.ss}; //AB
	v = {p.ff-a.ff,p.ss-a.ss}; //AP
	w = {p.ff-b.ff,p.ss-b.ss}; //BP
	z = {a.ff-b.ff,a.ss-b.ss}; //BA

	if(Dot(u,w) > 0)
		return dist(p,b);
	if(Dot(z,v) > 0)
		return dist(p,a);
	return fabs(cross(u,v))/dist(a,b);
}

bool equals(double a, double b){
	if(fabs(a-b) < EP)
		return true;
	return false;
}
double x, y;
	// intersect(mp(1,-3),mp(1,3),mp(-5,1),mp(5,1));
int intersect(pair<double,double> a, pair<double,double> b, pair<double,double> c, pair<double,double> d){
	double a1,b1,a2,b2;
	if(equals(a.ff, b.ff) && equals(c.ff,d.ff)) return 0;
	if(!equals(a.ff,b.ff)) a1 = (b.ss-a.ss)/(b.ff-a.ff), b1 = a.ss-a1*a.ff;
	if(!equals(c.ff,d.ff)) a2 = (d.ss-c.ss)/(d.ff-c.ff), b2 = c.ss-a2*c.ff;
	if(equals(a.ff,b.ff)) x = a.ff, y = a2*a.ff + b2;
	else if(equals(c.ff,d.ff)) x = c.ff, y = a1*c.ff+b1;
	else{
		if(equals(a1,a2)) return 0;
		x = (b2-b1/(a1-a2)), y =a1*x + b1;
	}
	if(!equals(dist(mp(x,y),a)+dist(mp(x,y),b), dist(a,b))) return 0;
	if(!equals(dist(mp(x,y),c)+dist(mp(x,y),d), dist(c,d))) return 0;
	return 1;
}

tipo_reta vet[505], vet2[505], reta[505];
int fim = 0;

int main(){
	double x1,x2,y1,y2;
	int n,i,j;

	scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
	
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%lf%lf%lf%lf", &vet[i].x1, &vet[i].y1, &vet[i].x2, &vet[i].y2);
	}

	for(i = 0; i < n; i++){
		if(x1 <= vet[i].x1 && vet[i].x1 <= x2 && y1 <= vet[i].y1 && vet[i].y1 <= y2){
			vet2[fim++] = vet[i];
		}
		else{
			double aux_y1, aux_y2;
			aux_y1 = vet[i].y1 + vet[i].y2 * (x1-vet[i].x1)/vet[i].x2;
			aux_y2 = vet[i].y1 + vet[i].y2 * (x2-vet[i].x1)/vet[i].x2;
			if(y1 <= aux_y1 && aux_y1 <= y2){
				if((x1-vet[i].x1)/vet[i].x2 > 0) {
					vet2[fim++] = vet[i];
					continue;
				}
			}
			if(y1 <= aux_y2 && aux_y2 <= y2){
				if((x2-vet[i].x1)/vet[i].x2 > 0) {
					vet2[fim++] = vet[i];
					continue;
				}
			}
			double temp1, temp2;
			temp1 = aux_y1;
			temp2 = aux_y2;
			if(temp1 > temp2) swap(temp1, temp2);
			if(temp1 < y1 && temp2 > y2){
				if(vet[i].y1 < y1){
					if((temp2 - vet[i].y1)/vet[i].y2 > 0) {
						vet2[fim++] = vet[i];
						continue;
					}
				}
				else {
					if((temp1 - vet[i].y1)/vet[i].y2 > 0) {
						vet2[fim++] = vet[i];
						continue;
					}
				}
			}
		}
	}
	if(fim == 1){
		printf("inf\n");
		return 0;
	}
	for(i = 0; i < fim; i++){
		double t, temp;
		t = (x1-vet[i].x1)/vet[i].x2;
		temp = vet[i].y1 + vet[i].y2*t;
		if(t > 0 && temp >= y1 && temp <= y2){
			reta[i] = tipo_reta(vet[i].x1, vet[i].y1, x1, temp);
			continue;
		}
		t = (x2-vet[i].x1)/vet[i].x2;
		temp = vet[i].y1 + vet[i].y2*t; 
		if(t > 0 && temp >= y1 && temp <= y2){
			reta[i] = tipo_reta(vet[i].x1, vet[i].y1, x2, temp);
			continue;
		}
		t = (y1-vet[i].y1)/vet[i].y2;
		temp = vet[i].x1 + vet[i].x2*t; 
		if(t > 0 && temp >= x1 && temp <= x2){
			reta[i] = tipo_reta(vet[i].x1, vet[i].y1, temp, y1);
			continue;
		}
		t = (y2-vet[i].y1)/vet[i].y2;
		temp = vet[i].x1 + vet[i].x2*t; 
		if(t > 0 && temp >= x1 && temp <= x2){
			reta[i] = tipo_reta(vet[i].x1, vet[i].y1, temp, y2);
		}
	}
	double ans = 1e9;
	for(i = 0; i < fim; i++){
		for(j = i+1; j < fim; j++){
			if(intersect(mp(reta[i].x1,reta[i].y1),mp(reta[i].x2,reta[i].y2),mp(reta[j].x1,reta[j].y1),mp(reta[j].x2,reta[j].y2)))
				ans = 0;
			ans = min(ans, dist_line(mp(reta[i].x1, reta[i].y1),mp(reta[j].x1,reta[j].y1), mp(reta[j].x2, reta[j].y2)) );
			ans = min(ans, dist_line(mp(reta[i].x2, reta[i].y2),mp(reta[j].x1,reta[j].y1), mp(reta[j].x2, reta[j].y2)) );
			ans = min(ans, dist_line(mp(reta[j].x1, reta[j].y1),mp(reta[i].x1,reta[i].y1), mp(reta[i].x2, reta[i].y2)) );
			ans = min(ans, dist_line(mp(reta[j].x2, reta[j].y2),mp(reta[i].x1,reta[i].y1), mp(reta[i].x2, reta[i].y2)) );
		}
	}

	printf("%.15lf\n", ans);

	return 0;
}