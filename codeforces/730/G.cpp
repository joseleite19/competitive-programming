#include <bits/stdc++.h>

#define ss second
#define ff first
#define mp make_pair
#define oo 1000006

using namespace std;

int n;

int d, s;

int main(){


	scanf("%d", &n);

	set<pair<int, int> > ans;

	for(int i = 0; i < n; i++){
		scanf("%d %d", &s, &d);

		// between
		bool can = true;
		for(set<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); it++){
			if(it->ff <= s && s <= it->ss)
				can = false;
		}

		// fits
		if(can){
			set<pair<int, int> >::iterator it = ans.lower_bound(mp(s, 0));
			if(it != ans.end() && s+d-1 >= it->ff)
				can = false;
		}

		if(can){
			printf("%d %d\n", s, s+d-1);
			ans.insert(mp(s, s+d-1));
		}
		else{
			// which

			int l = 1, r = 100000000;
			for(set<pair<int, int> >::iterator it = ans.begin(); it != ans.end(); it++){
				r = it->ff;
				if(r - l >= d){
					break;
				}
				l = it->ss+1;
			}
			printf("%d %d\n", l, l+d-1);
			ans.insert(mp(l, l+d-1));
		}
	}

	return 0;
}