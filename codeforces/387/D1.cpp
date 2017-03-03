#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int n, k, v[200005];

int main(){

	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	int changes = 0;

	int cnt = 0;
	for(int i = 0; i < n; i++)
		if(v[i] < 0) cnt++;

	if(!cnt){
		printf("0\n");
		return 0;
	}

	if(cnt > k){
		printf("-1\n");
		return 0;
	}

	k -= cnt;

	int i;
	for(i = 0; i < n; i++)
		if(v[i] < 0) break;

	vector<int> dist;

	int last = 0;
	while(i < n){
		int j = i;
	
		while(j < n && v[j] < 0) j++;
		if(j == n){
			last = 0;
			break;
		}
		// printf("%d %d\n", i, j);
	
		i = j;
		
		while(j < n && v[j] >= 0) j++;
		if(j == n){
			last = j-i;
			break;
		}
		// printf("%d %d\n", i, j);
	
		dist.push_back(j-i);
	
		i = j;
	}

	sort(dist.begin(), dist.end());

	changes = 2*((int)dist.size()+1);
	// printf("%d\n", changes);
	if(last == 0) changes--;

	for(int i = 0; i < (int) dist.size() && k >= 0; i++){
		if(k >= dist[i]){
			changes -= 2;
			k -= dist[i];
		}
	}
	if(last && k >= last){
		changes--;
		k -= last;
		last = 0;
	}

	printf("%d\n", changes);

	return 0;
}