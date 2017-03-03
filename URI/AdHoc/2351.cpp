#include <bits/stdc++.h>

using namespace std;

int n, k, v[100005], ans = 0;
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", v+i), ans += v[i];

	priority_queue<int, vector<int>, greater<int> > q;

	for(int i = k+1; i <= n; i++){
		q.push(v[i]);
		if(i % (k+1)) q.pop();
	}

	while(!q.empty()) ans -= q.top(), q.pop();

	printf("%d\n", ans);

	return 0;
}