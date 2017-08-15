#include <bits/stdc++.h>

using namespace std;
int n, v[200005];
int lef[200005], rig[200005];

int dist(int i, int j){
	if(i < j) return j - i;
	return n - (i - j);
}

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);

	stack<int> s;

	for(int i = 0; i < n; i++){
		while(!s.empty() && v[ s.top() ] >= v[i]) s.pop();
		s.push(i);
	}

	memset(lef, -1, sizeof lef);
	for(int i = 0; i < n; i++){
		while(!s.empty() && v[ s.top() ] >= v[i]) s.pop();
		if(!s.empty()){
			if(lef[i] == -1) lef[i] = s.top();			
		}
		s.push(i);
	}
	while(!s.empty()) s.pop();

	memset(rig, -1, sizeof rig);
	for(int i = n-1; i >= 0; i--){
		while(!s.empty() && v[ s.top() ] >= v[i]) s.pop();
		s.push(i);
	}

	for(int i = n-1; i >= 0; i--){
		while(!s.empty() && v[ s.top() ] >= v[i]) s.pop();
		if(!s.empty()){
			if(rig[i] == -1) rig[i] = s.top();
		}
		s.push(i);
	}

	int q = -1, w = -1, e = -1;
	for(int i = 0; i < n; i++){
		if(q == -1){
			q = lef[i], w = i, e = rig[i];
		}
		else{
			if(dist(q, w) + dist(w, e) > dist(lef[i], i) + dist(i, rig[i]))
			q = lef[i], w = i, e = rig[i];

		}
	}
	printf("%d %d %d\n", q+1, w+1, e+1);




	return 0;
}