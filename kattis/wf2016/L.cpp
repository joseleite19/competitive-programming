#include <bits/stdc++.h>

#define MOD (1000000007)
#define ff first
#define ss second
#define mp make_pair

using namespace std;

typedef long long ll;

ll resp = 0;

pair<ll,ll> v[1000005];

bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b){
	ll aa = a.ss - a.ff;
	ll bb = b.ss - b.ff;

	if(aa) aa =  aa/abs(aa);
	if(bb) bb = bb/abs(bb);

	if(aa != bb) return aa > bb;

	if(aa > 0)
		return a.ff < b.ff;
	
	if(aa == 0)
		return a.ff > b.ff;

	return (a.ss == b.ss ? a.ff > b.ff : a.ss > b.ss); 
}

int main(){
	ll n;

	scanf("%lld", &n);
	for(ll i = 0; i < n; i++)
		scanf("%lld%lld", &v[i].ff, &v[i].ss);

	sort(v,v+n,compare);

	ll atual = 0;
	for(ll i = 0; i < n; i++){
		// printf("%lld %lld\n", v[i].ff, v[i].ss);
		if(atual < v[i].ff){
			resp += v[i].ff-atual;
			atual = v[i].ss;
		}
		else{
			atual += v[i].ss - v[i].ff;
		}
	}

	printf("%lld\n", resp);

	return 0;
}