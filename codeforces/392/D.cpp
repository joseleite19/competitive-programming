#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000000000000

using namespace std;


int main(){

	int n;
	char s[100];

	scanf("%d %s", &n, s);

	long long pot[20];

	pot[0] = 1;

	for(int i = 1; i < 19; i++)
		pot[i] = 10*pot[i-1];

	long long tmp = 0;
	int cnt = 0;

	vector<long long> v;
	int sz = strlen(s);
	for(int i = sz-1; i >= 0; i--){
		long long k = pot[cnt]*(s[i] - '0') + tmp;
		// printf("%d %lld\n", i, k);
		if(k >= n){
			if(tmp) v.push_back(tmp);
			cnt = 0;
			int j;
			for(j = i+1; j < sz && s[j] == '0'; j++);
			cnt = j - i - 1;
			if(cnt > 18 || (s[i]-'0')*pot[cnt] >= n){
				while(cnt > 18 || (s[i]-'0')*pot[cnt] >= n){
					cnt--;
					v.push_back(0);
				}
			}
			else if(!tmp) v.push_back(0);
			tmp = (s[i]-'0')*pot[cnt];
			// printf("..%lld\n", tmp);
		}
		else{
			tmp = k;
		}
			cnt++;
	}
	v.push_back(tmp);

	long long ans = 0, x = 1;

	for(int i = 0; i < (int)v.size(); i++){
		// printf("asd %d\n", v[i]);
		ans += x*v[i];
		x *= n;
	}

	printf("%lld\n", ans);

	return 0;
}