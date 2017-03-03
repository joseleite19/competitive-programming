#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int ft[1001005];
int n, m, k;
int N;

void add(int x, int v){
	for(; x <= N; x += x&-x)
		ft[x] += v;
}

int sum(int x){
	int ans = 0;
	for(; x; x -= x&-x)
		ans += ft[x];
	return ans;
}

int bs(int id, int x){

	int l = 0, r = n;

	x += sum(id-1);

	int ptr = N;
	int ans = n;

	int lg = 31 - __builtin_clz(N);
	while(1){
		lg--;
		// printf("%d %d %d %d\n", ptr, ft[ptr], x, lg);
		if(ft[ptr] == x){
			ans = min(ans, ptr);
			ptr -= 1 << lg;
		}
		if(lg < 0) break;
		if(ptr == 0) break;
		if(ft[ptr] > x) ptr -= 1 << lg;
		else if(ft[ptr] < x){
			x -= ft[ptr];
			ptr += 1 << lg;
		}
		
	}
	// printf("==================%d\n", ans);

	// while(l <= r){
	// 	int mid = (l+r)/2;
	// 	int tmp = sum(mid);

	// 	if(tmp >= x){
	// 		r = mid-1;
	// 		if(tmp == x) ans = min(ans, mid);
	// 	}
	// 	else{
	// 		l = mid+1;
	// 	}
	// }
	return ans;
}

int f(int id, int x){

	int y = sum(n) - sum(id-1);

	if(y < x){
		x -= y;
		x %= sum(n);
		if(x == 0) x = sum(n);
		return f(1,x);
	}
	return bs(id,x);

}

int main(){

	scanf("%d %d %d", &n, &m, &k);
	N = 1;
	while(N < n) N <<= 1;

	for(int i = 1; i <= n; i++)
		add(i, 1);

	int steps = 0;
	int v = 1;

	while(1){
		int ptr = f(v,m);

		steps++;
		if(ptr == k) break;
		add(ptr,-1);
		v = f(ptr,1);
	}


	printf("%d\n",steps);



	return 0;
}