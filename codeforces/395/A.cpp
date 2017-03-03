#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int lcm(int a, int b){
	return a*b/gcd(a, b);
}

int main(){
	int n, m, z;

	scanf("%d %d %d", &n, &m, &z);

	printf("%d\n", z / lcm(n, m));

	return 0;
}