#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

long long get(long long n, long long p){
	long long ret = 0;

	long long s = p;

	while(n > p){
		ret += n / p;
		p *= s;
	}
	return ret;
}

int main(){
	vector<pair<long long, long long> > v;

	long long n;

	scanf("%lld", &n);

	long long tmp = n;
	for(long long i = 2; i*i <= tmp; i++){
		if(tmp % i == 0){
			long long cnt = 0;
			while(tmp % i == 0){
				tmp /= i;
				cnt++;
			}
			v.push_back(mp(i, cnt));
		}
	}
	if(tmp > 1){
		v.push_back(mp(tmp, 1));
	}

	int can = true;
	for(int i = 0; i < (int)v.size(); i++){
		if(get(n-1, v[i].ff) < v[i].ss)
			can = false;
	}

	printf("%s\n", can ? "YES" : "NO");






	return 0;
}