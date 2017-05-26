#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;
long long a[100005], b[100005], x, sa, sb;
bool e[100005];


int main(){

	scanf("%d", &n);

	priority_queue<pair<long long, int>, vector<pair<long long, int> >,
	greater<pair<long long, int> > > qa, qb;

	for(int i = 0; i < n; i++){
		scanf("%lld", a+i);
		sa += a[i];
		qa.push(mp(a[i], i));
	}

	set<int> ans;
	for(int i = 0; i < n; i++){
		scanf("%lld", b+i);
		sb += b[i];
		qb.push(mp(b[i], i));
		ans.insert(i);
	}

	int target = n/2 + 1;

	long long r = 2*sa, l = 2*sb;

	// for(int i = n; i > target; i--){
	while(ans.size() > target){
		while(!qa.empty() && e[ qa.top().ss ]) qa.pop();
		while(!qb.empty() && e[ qb.top().ss ]) qb.pop();
		if(qa.empty() && qb.empty()) break;
		if(qa.empty()){
			while(e[ qb.top().ss ]) qb.pop();
			if(qb.empty()) continue;
			e[ qb.top().ss ] = 1;
			r -= 2*a[qb.top().ss];
			l -= 2*b[qb.top().ss];
			ans.erase(qb.top().ss);
			qb.pop();
			continue;
		}
		if(qb.empty()){
			while(e[ qa.top().ss ]) qa.pop();
			if(qa.empty()) continue;
			e[ qa.top().ss ] = 1;
			r -= 2*a[qa.top().ss];
			l -= 2*a[qa.top().ss];
			ans.erase(qa.top().ss);
			qa.pop();
			continue;
		}

		long long tmpa = 0, tmpb = 0; // take from a, take from b
		{//take from a
			tmpa = min(r - 2*a[qa.top().ss] - sa, l - 2*b[qa.top().ss] - sb);
		}

		{//take from b
			tmpb = min(r - 2*a[qb.top().ss] - sa, l - 2*b[qb.top().ss] - sb);
		}

		if(tmpa > tmpb){
			e[ qa.top().ss ] = 1;
			r -= 2*a[qa.top().ss];
			l -= 2*b[qa.top().ss];
			ans.erase(qa.top().ss);
			qa.pop();
		}
		else{
			e[ qb.top().ss ] = 1;
			r -= 2*a[qb.top().ss];
			l -= 2*b[qb.top().ss];
			ans.erase(qb.top().ss);
			qb.pop();
		}
	}

	printf("%d\n", int(ans.size()));

	for(set<int>::iterator it = ans.begin(); it != ans.end(); it++){
		printf("%d ", (*it)+1);
	}

	return 0;
}