#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

char t[50004], p[50004];


int v[50004];
int v2[50004];

vector<int> z_function(string s) {
	int n = (int)s.length();
	vector<int> z(n);
	int l = 0, r = 0;
	for(int i = 1; i < n; i++){
		if(i <= r) z[i] = min(r-i+1, z[i-l]);
		while(i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
		if(i+z[i]-1 > r) l = i, r = i+z[i]-1;
	}
	return z;
}

vector<int> pf(string p){

// 	// printf("%s\n", p);
	int n = p.length();
	vector<int>v(n+1, 0);
	for(int i = 2; i <= n; i++){
		v[i] = v[i-1];
		while(v[i] > 0 && p[ v[i] ] != p[i-1]) v[i] = v[ v[i] ];
		if(p[ v[i] ] == p[i-1]) v[i]++;
		// printf("%d %c %c\n", v[i], p[i-1], p[v[i]]);
	}
	for(int i = 0; i < n; i++)
		v[i] = v[i+1];
	return v;

// 	// for(int i = 1; i <= n; i++)
// 	// 	printf("%d ", v[i]);
// 	// printf("\n");

// 	int j = 0;

// 	for(int i = 0; i < n; i++){
		
// 		while(j > 0 && p[ j ] != t[i]) j = v[ j ];
// 		if(p[ j ] == t[i]) j++;
// 		// if(j == n){
// 		// 	j = p[j];
// 		// }
// 		// printf("%d\n", j);
// 		v2[i] = j;
// 	}

// 	for(int i = 0; i < n; i++)
// 		printf("%d ", v2[i]);
// 	printf("\n");
// 	int k = n-1;

// 	int cnt = 0;
// 	for(int i = 1; i < n; i++){
// 		if(v2[i] <= v2[i-1]){
// 			k = i;
// 		}
// 	}
}

int main(){

	scanf("%s %s", t, p);

	int n;
	n = strlen(t);
	// pf();

	string a = t;
	string b = p;

	// if(a == b){
	// 	printf("Yes\n0\n");
	// 	return 0;
	// }

	string aa = a;
	reverse(aa.begin(), aa.end());
	vector<int> z1 = z_function(string(b + '#' + a));

	// a = aa;
	aa = b;
	reverse(aa.begin(), aa.end());
	vector<int> z2 = pf(string(aa + '#' + a));

	// for(int i = n+1; i < z1.size(); i++)
	// 	printf("%d %d\n", z1[i], z2[i]);

	int k = -1;
	for(int i = n+1; i < (int)z1.size(); i++){
		// printf("%d %d\n", z1[i], z2[z2.size() - i + (n+1)]);
		// printf("%d %d\n", z1[i], z2[i]);
		if(z1[i] + z2[i-1] == n){
			k = i - n - 1;
			break;
		}
	}
	if(k == -1) printf("No\n");
	else printf("Yes\n%d\n", k);









	return 0;
}