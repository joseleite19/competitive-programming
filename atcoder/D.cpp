#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

pair<long long, long long> maxx(pair<long long, long long> a, pair<long long, long long> b){
	if(a.ff * b.ss > b.ff * a.ss) return a;
	return b;
}

long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}


int n, m, a, b;
long long v[52];
long long w[52];
pair<long long, long long> mx = mp(0LL, 1LL);

pair<long long, long long> bettera[55];
pair<long long, long long> betterb[55];

void f(long long sum, int qnt, int i, int fs){
	if(fs && i == n/2){
		if(bettera[qnt].ff < sum) bettera[qnt] = mp(sum, 1);
		else if(bettera[qnt].ff == sum) bettera[qnt].ss++;
	}
	else if(!fs && i == n){
		if(betterb[qnt].ff < sum) betterb[qnt] = mp(sum, 1);
		else if(betterb[qnt].ff == sum) betterb[qnt].ss++;
	}
	else{
		f(sum, qnt, i+1, fs);
		f(sum+v[i], qnt+1, i+1, fs);
	}
}

int main(){

	scanf("%d %d %d", &n, &a, &b);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	sort(v, v+n);

	f(0, 0, 0, 1);
	f(0, 0, n/2, 0);

	long long cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			pair<long long, long long> tmp = mp(bettera[i].ff + betterb[j].ff, i+j);
			if(tmp.ss < a || tmp.ss > b) continue;

			long long g = gcd(tmp.ff, tmp.ss);
			tmp.ff /= g;
			tmp.ss /= g;

			if(tmp == mx){
				cnt += 1LL * bettera[i].ss * betterb[j].ss;
			}
			else if(maxx(tmp, mx) == tmp){
				mx = tmp;
				cnt = 1LL * bettera[i].ss * betterb[j].ss;
			}
		}
	}

	printf("%lf\n", (double)mx.ff/mx.ss);
	printf("%lld\n", cnt);



	return 0;
}