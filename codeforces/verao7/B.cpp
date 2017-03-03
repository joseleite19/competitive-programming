#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int v[200005];
int ans[200005];

int n;

vector<int> z_function(vector<int> s) {
	int n = (int)s.size();
	vector<int> z(n);
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i <= r) z[i] = min(r-i+1, z[i-l]);
		while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
		if(i+z[i]-1 > r) l = i, r = i+z[i]-1;
	}
	return z;
}

int main(){

	char s[10000];
	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%d", v+i);


	vector<int> tmp(n, 0);

	int ptr = 1;
	for(int i = 0; i < n; i++){
		if(v[i]){
			tmp[i] = tmp[ v[i]-1 ];
		}
		else tmp[i] = ptr++;
	}

	vector<int> zz = z_function(tmp);
	
	for(int i = 0; i < n; i++)
		printf("%d ", zz[i]);
	printf("\n");


	return 0;
}