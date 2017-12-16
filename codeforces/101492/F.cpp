#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

	ll r;

	scanf("%lld",&r);

	ll v[11];

	for(int i = 1; i <= 10; i++){
		v[i] = i*r;
		v[i] *= v[i];
	}

	ll resp = 0;

	for(int i = 0; i < 3; i++){
		ll x,y;

		scanf("%lld %lld", &x, &y);

		ll dist = x*x + y*y;

		for(int i = 1; i <= 10; i++){
			if(dist <= v[i]){
				resp += 10-i+1;
				break;
			}
		}
	}

	printf("%lld\n",resp );

    return 0;
}
