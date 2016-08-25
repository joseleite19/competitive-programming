#include <bits/stdc++.h>

using namespace std;
map<int, int> v;
int f(long long n){
	// if(v.find(n) != v.end()) return v[n];
	if(n == 1) return 0;
	if(n & 1) return 1 + f(3*n+1);
	return 1 + f(n/2);
}

int main(){
	bitset<10000005> m;
	bitset<10000005> ncalc;
	int n, k;

	ncalc.set();

	int maior = 0;

	long long sum = 0;

	// for(int i = 1; i <= 10000000; i++){
	// 	int aux = f(i);
	// 	maior = max(maior, aux);
	// 	sum += aux;
	// }
	// printf("%d %lld\n", maior, sum);
	// return 0;
	// 	printf("%d\n", f(i));

	// memset(m, -1, sizeof m);


	scanf("%d %d", &n, &k);

	for(int i = n; i >= 1; i--){
		if(!ncalc[i]) continue;
		int x = i;
		stack<int> s;
		s.push(x);
		bool deuruim = false;
		int j = 1;
		do{
			if(x & 1) x = 3*x + 1;
			else x /= 2;

			if(j == k) break;
			j++;
			if(x > n){
				deuruim = true;
				break;
			}
			// printf("%d %d %d\n", x, (bool)ncalc[x], (bool)tanaPilha[x]);
			if(!ncalc[x]) break;
			// if(s.size() == k) break;
			s.push(x);
			// getchar();
		}while(x != 1);
		// getchar();
		if(x == 1) deuruim = false;
		m[i] = !deuruim;
		ncalc[i] = 0;
		while(!s.empty()){
			m[ s.top() ] = deuruim ? 0 : 1;
			ncalc[ s.top() ] = deuruim && s.size() >= k ? 1 : 0;
			s.pop();
		}
		// printf("%d %d\n", i, (bool)m[i]);
	}
	int count = 0;
	for(int i = 1; i <= n; i++)
		if(m[i]){
			// printf("..%d\n", i);
			count++;
		}

	printf("%d\n", count);

	return 0;
}