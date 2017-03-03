#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

long long ts, tf, t, v[100005];
int n;

int main(){

	scanf("%lld %lld %lld", &tf, &ts, &t);

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	long long last = tf;
	long long ans = 0, tmp = tf;

	for(int i = 0; i < n; i++){
		if(v[i] > last && last+t <= ts){
			printf("%lld\n", last);
			return 0;
		}

		if(v[i] <= last){
			if(i == 0 || (i > 0 && v[i] != v[i-1])){
				if(v[i]-1+t <= ts && last - (v[i]-1) < tmp){
					ans = v[i]-1;
					tmp = last - (v[i]-1);
				}
			}
		}

		if(v[i] >= last) last = v[i] + t;
		else last += t;
	}

	if(last+t <= ts) ans = last;

	printf("%lld\n", ans);



	return 0;
}