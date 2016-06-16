#include <bits/stdc++.h>

using namespace std;

int main(){
	vector<pair<int, int> > v;
	int n;

	scanf("%d", &n);
	v.assign(n, pair<int, int>());

	for(int i = 0; i < n; i++)
		scanf("%d %d", &v[i].first, &v[i].second);

	sort(v.begin(), v.end());

	int ans = 0;
	for(int i = 0; i < n; i++){ // pega em ordem pelo x e depois y
		stack<int> top, down;
		for(int j = 0; j < i; j++){ // os que vieram antes do i têm coordenada x menor
			if(v[j].second > v[i].second){
				while(!top.empty() && top.top() > v[j].second) top.pop();
				top.push(v[j].second);
			}
			else{
				while(!down.empty() && down.top() < v[j].second) down.pop();
				down.push(v[j].second);
			}
		}
		ans += top.size() + down.size();
	}
	printf("%d\n", ans);

	return 0;
}