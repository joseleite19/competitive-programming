#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int s, p;
long double f(int x){
	return x * pow(p, 1.0/x);
}

int main(){

	scanf("%d %d", &s, &p);

	int lo = 1, hi = s;

	int ans = -1;

	for(int i = 1; i < 100000; i++){
		if(f(i) <= s){
			ans = i;
			break;
		}
	}
	if(p == 1 && s < ans) ans = s;

	// while(lo + 1 < hi){
	// 	int tmp = (hi - lo + 1) / 2;
	// 	int mid = lo + tmp;
	// 	if(f(mid)) lo = mid;
	// 	else hi = mid-1;
	// }

	// if(!f(hi)) hi--;
	// if(hi == 1 && !f(hi)){
	// 	printf("-1\n");
	// 	return 0;
	// }

	printf("%d\n", ans);





	return 0;
}