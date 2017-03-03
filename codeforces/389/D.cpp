#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, k;
long long v[100005];

char tmp[100005];

set<string> s;

map<string, vector<long long> > m;

int main(){

	scanf("%d %d", &k, &n);

	for(int i = 0; i < k; i++){
		scanf(" %s %lld", tmp, v+i);
		string ss = tmp;
		m[ ss ].push_back(v[i]);

		string sr = ss;
		reverse(sr.begin(), sr.end());
		if(s.find(ss) == s.end() && s.find(sr) == s.end()) s.insert(ss);
	}

	for(map<string, vector<long long> >::iterator it = m.begin(); it != m.end(); it++)
		sort(it->ss.begin(), it->ss.end(), greater<int>());

	long long ans = 0;
	long long better = 0;
	for(set<string>::iterator it = s.begin(); it != s.end(); it++){
		string ss = *it;
		string sr = ss;
		reverse(sr.begin(), sr.end());
		vector<long long> & v1 = m[ ss ];
		vector<long long> & v2 = m[ sr ];
		bool inv = false;
		if(ss == sr) inv = true;
		int i;
		if(inv){
			for(i = 0; i < (int)v1.size() && i+1 < (int)v1.size(); i += 2){
				long long a = v1[i];
				long long b = v1[i+1];
				long long c = a+b;
				// printf("(%lld %lld)\n", a, b);
				if(c > 0){
					ans += c;
					better = max(better, b-c);
					better = max(better, a-c);
				}
				else{
					better = max(better, b);
					better = max(better, a);
				}
			}
			if(i < v1.size()) better = max(better, v1[i]);
		}
		else{
			for(i = 0; i < (int)v1.size() && i < (int)v2.size(); i++){
				long long a = v1[i];
				long long b = v2[i];
				// printf("(%lld %lld) %s %s\n", a, b, ss.c_str(), sr.c_str());
				long long c = a+b;
				if(c > 0) ans += c;
			}
		}
	}


	// printf("%lld\n", better);
	if(better > 0) ans += better;

	printf("%lld\n", ans);




	return 0;
}