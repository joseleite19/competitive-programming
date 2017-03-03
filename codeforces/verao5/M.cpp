#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

int main(){
	int n;
	set<pair<int, int> > s;

	int x;
	vector<pair<pair<short, short>, short> > v;

	scanf("%d", &n);

	long long tmp = n;
	if(tmp % 3){
		if(tmp*(tmp-1)*(tmp-2)/6 > n*n){
			printf("-1\n");
			return 0;
		}
		for(int i = 1; i <= n; i++){
			for(int j = i+1; j <= n; j++){
				for(int k = j+1; k <= n; k++){
					v.push_back(mp(mp(i, j), k));
				}
			}
		}
	}
	else{
		printf("%d\n", n/3);
		for(int i = 1; i <= n; i += 3)
			printf("%d %d %d\n", i, i+1, i+2);
		return 0;
	}


	bool ok = true;

	// for(int i = 1; i <= n; i++){
	// 	s.insert(mp(0, i));
	// }

	// bool ok = true;

	// while(1){

	// 	if(v.size() > n*n){
	// 		ok = false;
	// 		break;
	// 	}
	// 	pair<pair<short, short>, short> tmp;
	// 	pair<int, int> tmp2;

	// 	tmp2 = *s.begin();
	// 	s.erase(tmp2);
	// 	tmp.ff.ff = tmp2.ss;
	// 	tmp2.ff++;
	// 	s.insert(tmp2);

	// 	tmp2 = *s.begin();
	// 	s.erase(tmp2);
	// 	tmp.ff.ss = tmp2.ss;
	// 	tmp2.ff++;
	// 	s.insert(tmp2);

	// 	tmp2 = *s.begin();
	// 	s.erase(tmp2);
	// 	tmp.ss = tmp2.ss;
	// 	tmp2.ff++;
	// 	s.insert(tmp2);

	// 	v.pb(tmp);

	// 	if(s.begin()->ff == prev(s.end())->ff) break;
	// }

	if(!ok){
		printf("-1\n");
		return 0;
	}

	// sort(v.begin(), v.end());

	printf("%d\n", (int)v.size());
	for(int i = 0; i < (int)v.size(); i++)
		printf("%hd %hd %hd\n", v[i].ff.ff, v[i].ff.ss, v[i].ss);



	return 0;
}