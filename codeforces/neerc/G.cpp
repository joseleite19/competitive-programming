#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int l[100], r[100];
int q[100];

int check[256];

void file(){
	freopen("grave.in", "r", stdin);
	freopen("grave.out", "w", stdout);
}

int main(){
	//file();
	int n,xg,yg,Xg,Yg,xc,yc,Xc,Yc,h,w;

	scanf("%d%d%d%d", &xg, &yg, &Xg, &Yg);
	scanf("%d%d%d%d", &xc, &yc, &Xc, &Yc);
	scanf("%d%d", &w, &h);
	
	if(yc-yg >= h && Xg-xg >= w){
		printf("Yes\n");
		return 0;
	}
	if(Yg-Yc >= h && Xg-xg >= w){
		printf("Yes\n");
		return 0;
	}
	if(xc-xg >= w && Yg-yg >= h){
		printf("Yes\n");
		return 0;
	}
	if(Xg-Xc >= w && Yg-yg >= h){
		printf("Yes\n");
		return 0;
	}
	printf("No\n");

}