#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

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

char t[1000006], p[1000006];
int k;

int main(){

	scanf("%s %s %d", t, p, &k);

	string a = t;
	string b = p;
	vector<int> z1 = z_function(b + "#" + a);

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	vector<int> z2 = z_function(b + "#" + a);

	{
		vector<int> tmp;
		for(int i = b.size()+1; i < (int)z1.size(); i++)
			tmp.push_back(z1[i]);
		z1 = tmp;
	}

	{
		vector<int> tmp;
		for(int i = b.size()+1; i < (int)z2.size(); i++)
			tmp.push_back(z2[i]);
		z2 = tmp;
	}

	vector<int> occur;

	reverse(z2.begin(), z2.end());

	for(int i = 0; i <= (int)z1.size() - b.size(); i++)
		if(z1[i] + z2[i + b.size()-1] >= int(b.size()) - k)
			occur.push_back(i+1);

	printf("%d\n", (int)occur.size());

	for(int i = 0; i < (int)occur.size(); i++)
		printf("%d ", occur[i]);
	printf("\n");

	return 0;
}