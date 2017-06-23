#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n;

pair<long long, pair<long long, int> > v[100005];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld", &v[i].ff);

	set<int> ans;
	for(int i = 0; i < n; i++)
		scanf("%lld", &v[i].ss.ff), v[i].ss.ss = i;

    sort(v, v+n); reverse(v, v+n);

    ans.insert(v[0].ss.ss);

    for(int i = 1; i+1 < n; i += 2){
        if(v[i].ss.ff >= v[i+1].ss.ff) ans.insert(v[i].ss.ss);
        else ans.insert(v[i+1].ss.ss);
    }

	int target = n/2 + 1;

    for(int i = n-1; ans.size() < target; i--)
        ans.insert(v[i].ss.ss);

	printf("%d\n", int(ans.size()));

	for(set<int>::iterator it = ans.begin(); it != ans.end(); it++)
		printf("%d ", (*it)+1);
	
    printf("\n");

	return 0;
}
