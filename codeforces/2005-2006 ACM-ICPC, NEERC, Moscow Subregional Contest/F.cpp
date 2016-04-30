/* Fractions */

/* P / Q >= A / B      *
 * P / Q < (A + 1) / B */

#include <bits/stdc++.h>

using namespace std;

int main(){
	int a, p, q, b;

	scanf("0.%d", &a);

	int aux = a;
	b = 1;
	while(aux){
		b *= 10;
		aux /= 10;
	}
				   
	for(q = 1; q < 100000001; q++){
		int lowerbound, upperbound;
		if(((long long)a * q) % b)
			lowerbound = (long long) a * q / b + 1;
		else
			lowerbound = (long long) a * q / b;
		
		if(((long long)(a+1) * q) % b)
			upperbound = (long long)(a+1) * q / b;
		else
			upperbound = (long long)(a+1) * q / b - 1;
		
		if(upperbound >= lowerbound){
			p = lowerbound;
			break;
		}
	}
	printf("%d %d\n", p, q);

	return 0;
}
