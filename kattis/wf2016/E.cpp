#include <bits/stdc++.h>

#define MOD (1000000007)
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

vector<ll> f(ll num, ll b){
	vector<ll> ret;
	
	while(num){
		ret.push_back(num%b);
		num/=b;
	}

	return ret;
}

bool f2(ll num, ll b){
	while(num){
		if(num%b >= 10) return 0;
		num/=b;
	}

	return 1;
}

int main(){
	ll y,low;

	scanf("%lld%lld", &y,&low);
	
	ll m,l,r;

	l = 10, r = y;

	vector<ll> num = f(low,10);

	while(l < r){
		// printf("%lld %lld\n", l,r);
		m = ((l+r)>>1) + 1;
		vector<ll> tmp = f(y,m);
		int flag = 1;

		if(tmp.size() > num.size()) flag = 2;
		else if(tmp.size() == num.size()){
			for(int i = (int)num.size()-1; i >= 0; i--){
				if(tmp[i] > num[i]){
					flag = 2;
					break;
				}
				else if(tmp[i] < num[i]){
					flag = 0;
					break;
				}
			}
		}
		else flag = 0;

		if(!flag){
			r = m-1;
		}
		else l = m;
	}

	ll ans = 0;

	for(int k = 0; k < 10; k++){
		ll xx = y - k;

		for(ll i = 2; i*i <= xx; i++){
			if(xx % i == 0){
				if(i <= l){
					vector<ll> tmp = f(y,i);
					bool go = 1;
					for(int j = tmp.size() - 1; j >= 0; j--)
						if(tmp[j] >= 10)
							go = 0;

					if(go) ans = max(ans, i);
				}
				
				if(xx/i <= l){
					vector<ll> tmp = f(y,xx/i);
					bool go = 1;
					for(int j = tmp.size() - 1; j >= 0; j--)
						if(tmp[j] >= 10)
							go = 0;
					if(go) ans = max(ans, xx/i);
				}
			}
		}
	}

	printf("%lld\n", ans);

	return 0;
}