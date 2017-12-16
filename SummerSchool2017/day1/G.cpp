#include <bits/stdc++.h>

using namespace std;

struct bit{
	vector<long long> ft;
	int n;

	void add(int x, long long v){
		for(; x <= n; x += x&-x)
			ft[x] += v;
	}
	long long sum(int x){
		long long ans = 0;
		for(; x; x -= x&-x)
			ans += ft[x];
		return ans;
	}
	bit(int n = 0): n(n), ft(n+1, 0) {}
};

long long v[100005];
long long f[100005];
int k[100005];

map<long long, int> vai;
map<int, long long> volta;

int n;
int m;
int ptr = 1;

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", v+i);

	scanf("%d", &m);

	for(int i = 0; i < m; i++){
		scanf("%d %lld", k+i, f+i);
		k[i]--;
	}

	if(n == 1){
		for(int i = 0; i < m; i++)
			printf("1\n");
		return 0;
	}

	multiset<long long> s;
	{
		vector<long long> tmp;
		for(int i = 0; i < n; i++){
			tmp.push_back(v[i]);
			s.insert(v[i]);
		}
		
		for(int i = 0; i < m; i++)
			tmp.push_back(f[i]);

		sort(tmp.begin(), tmp.end());
		for(int i = 0; i < (int)tmp.size(); i++){
			if(!vai.count(tmp[i])){
				vai[ tmp[i] ] = ptr;
				volta[ptr] = tmp[i];
				ptr++;
			}
		}
	}

	bit b(ptr+1);

	for(int i = 0; i < n; i++)
		b.add(vai[ v[i] ], v[i]);

	int ans = 2;
	multiset<long long>::iterator it = s.begin();

	long long target = *it;
	it++;
	target += *it;

	while(1){
		it = s.lower_bound(target);
		if(it == s.end()) break;
		if(*it >= b.sum(vai[*it]-1)) ans++;
		target = b.sum(vai[*it]);
	}

	printf("%d\n", ans);

	for(int i = 0; i < m; i++){
		ans = 2;

		b.add(vai[ v[ k[i] ] ], -v[ k[i] ]);
		it = s.find(v[ k[i] ]);
		s.erase(it);
		v[ k[i] ] = f[i];
		s.insert(f[i]);

		b.add(vai[ f[i] ], f[i]);

		it = s.begin();
		target = *it;
	// printf("asd %d ", *it);
		it++;
	// printf("%d\n", *it);
		target += *it;

		while(1){
			it = s.lower_bound(target);
			if(it == s.end()) break;
			// printf("#%lld %lld\n", target, *it);
			if(*it >= b.sum(vai[*it]-1)) ans++;
			target = b.sum(vai[*it]);
		}
		printf("%d\n", ans);
	}

	return 0;
}