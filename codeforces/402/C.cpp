#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

int n, k;

pair<int, int> v[200005];

int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i].ff);

	for(int i = 0; i < n; i++)
		scanf("%d", &v[i].ss);

	int cnt = 0;
	long long ans = 0;

	vector<int> delta;

	for(int i = 0; i < n; i++){
		if(v[i].ff <= v[i].ss){
			ans += v[i].ff;
			cnt++;
		}
		else{
			ans += v[i].ss;
			delta.push_back(v[i].ff - v[i].ss);
		}
	}

	sort(delta.begin(), delta.end());

	for(int i = 0; cnt < k; i++){
		ans += delta[i];
		cnt++;
	}

	printf("%lld\n", ans);



	return 0;
}