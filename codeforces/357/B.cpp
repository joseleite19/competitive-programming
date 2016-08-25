#include <bits/stdc++.h>
#define INF 10000000000000007
using namespace std;

long long gcd(long long a, long long b){
	return (b ? gcd(b, a % b) : a);
}

typedef pair<long long, long long> bezout;
bezout find_bezout(long long a, long long b) {
	if (b == 0) return bezout(1, 0);
	bezout u = find_bezout(b, a % b);
	return bezout(u.second, u.first - (a/b) * u.second);
}
// Determina x e y tais que ax + by == c. (x, y) eh uma solucao particular para
// o problema. As demais solucoes sao da forma: (x + bk, y − ak), para todo
// long longeiro k, positivo ou negativo. Retorna (INF,INF) se nao tiver solucao.
bezout solve_linear_diophantine(long long a, long long b, long long c) {
	long long d = gcd(a, b);
	if ( c % d ) return bezout(INF, INF);
	long long new_c = c / d;
	bezout asw = find_bezout( a / d, b / d );
	asw.first *= new_c; asw.second *= new_c;
	if(asw.second == 0 || asw.first == 0){
		asw.second += a/d;
		asw.first -= b/d;
	}
	return asw;
}

int main(){
	// pair<long long, long long> ret = find_bezout(1234567, 123456);
	// pair<long long, long long> ret2 = find_bezout(ret.second, 1234);
	pair<long long, long long> ret3 = solve_linear_diophantine(1234567, 123456, gcd(1234567, 123456));
	pair<long long, long long> ret4 = solve_linear_diophantine(1, 1234, 1359257);
	pair<long long, long long> ret5 = solve_linear_diophantine(1, 1234, 17851817);

	printf("%lld %lld %lld %lld %lld %lld\n", ret3.first, ret3.second, ret4.first, ret4.second, ret5.first, ret5.second);
	// printf("%lld %lld %lld %lld\n", ret.first, ret.second, ret2.first, ret2.second);
	// printf("%lld %lld %lld %lld\n", gcd(1359257, 1234), gcd(1359257, 2544), gcd(1359257, -45), gcd(1359257, 12863));

	return 0;
}