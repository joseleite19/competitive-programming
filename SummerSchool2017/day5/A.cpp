#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int d[100005];

int main(){

	int n = 100005;
	for(int i = 1; i < n; i++)
		for(int j = i; j < n; j += i)
			d[j]++;


	for(int i = 1; i <= 100; i++){
		int tmp = 0;
		for(int j = i-1; j >= 0; j--)
			if(d[j] > d[i])
				tmp++;
		if(tmp <= 1)
			printf("%d %d\n", i, d[i]);
	}



	return 0;
}