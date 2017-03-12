#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

bitset<505> transition[64][2][505];

int mark[64][2][505];

bitset<505> mat[2][505];

int n;

bitset<505> f(int i, int state, int inv){
	if(mark[i][inv][state]) return transition[i][inv][state];
	mark[i][inv][state] = 1;

	bitset<505> &ans = transition[i][inv][state];

	if(i == 0) ans = mat[inv][state];
	else{
		bitset<505> tmp = f(i-1, state, inv);
		for(int j = 0; j < 505; j++)
			if(tmp[j])
				ans |= f(i-1, j, !inv);
	}

	return ans;
}

int main(){
	int m;

	scanf("%d %d", &n, &m);

	for(int i = 0; i < m; i++){
		int u, v, t;
		scanf("%d %d %d", &u, &v, &t);
		u--, v--;
		transition[0][t][u][v] = 1;
	}

	for(int i = 1; i < 60; i++)
		for(int inv = 0; inv <= 1; inv++)
			for(int s = 0; s < n; s++)
				for(int j = 0; j < n; j++)
					if(transition[i-1][inv][s][j])
						transition[i][inv][s] |= transition[i-1][!inv][j];

	bitset<505> states;
	states.set(0);

	long long ans = 0;
	int inv = 0;
	for(int i = 59; i >= 0; i--){
		bitset<505> tmp;
		for(int j = 0; j < 505; j++)
			if(states[j])
				tmp |= transition[i][inv][j];

		if(tmp.any()){
			states = tmp;
			inv ^= 1;
			ans += (1LL << i);
		}
	}

	printf("%lld\n", ans <= 1000000000000000000 ? ans : -1);

	return 0;
}