#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define oo 1000000000

using namespace std;

pair<int, int> p[4];

int area(pair<int, int> & p1, pair<int, int> & p2, pair<int, int> & p3, pair<int, int> & p4){
	int ans = p1.ff * p2.ss;
	ans += p2.ff * p3.ss;
	ans += p3.ff * p4.ss;
	ans += p4.ff * p1.ss;

	ans -= p1.ss * p2.ff;
	ans -= p2.ss * p3.ff;
	ans -= p3.ss * p4.ff;
	ans -= p4.ss * p1.ff;

	return ans;
}

int main(){

	for(int i = 0; i < 3; i++)
		scanf("%d %d", &p[i].ff, &p[i].ss);

	set<pair<int,int> > ans;
	pair<int, int> tmp;

	tmp = mp(p[0].ff - p[1].ff, p[0].ss - p[1].ss);
	ans.insert(mp(p[2].ff - tmp.ff, p[2].ss - tmp.ss));

	tmp = mp(p[1].ff - p[0].ff, p[1].ss - p[0].ss);
	ans.insert(mp(p[2].ff - tmp.ff, p[2].ss - tmp.ss));


	tmp = mp(p[0].ff - p[2].ff, p[0].ss - p[2].ss);
	ans.insert(mp(p[1].ff - tmp.ff, p[1].ss - tmp.ss));

	tmp = mp(p[2].ff - p[0].ff, p[2].ss - p[0].ss);
	ans.insert(mp(p[1].ff - tmp.ff, p[1].ss - tmp.ss));


	tmp = mp(p[2].ff - p[1].ff, p[2].ss - p[1].ss);
	ans.insert(mp(p[0].ff - tmp.ff, p[0].ss - tmp.ss));

	tmp = mp(p[1].ff - p[2].ff, p[1].ss - p[2].ss);
	ans.insert(mp(p[0].ff - tmp.ff, p[0].ss - tmp.ss));




	



	// int id[] = {0, 1, 2, 3};
	// for(int x = -1000; x <= 1000; x++){
	// 	for(int y = -1000; y <= 1000; y++){
	// 		p[3] = mp(x, y);
	// 		bool can = false;
	// 		int i = 0;
	// 		do{
	// 			i++;
	// 			pair<int, int> & p1 = p[ id[0] ];
	// 			pair<int, int> & p2 = p[ id[1] ];
	// 			pair<int, int> & p3 = p[ id[2] ];
	// 			pair<int, int> & p4 = p[ id[3] ];
	// 			// if(area(p1, p2, p3, p4) > 0){
	// 				pair<int, int> tmp = mp(p1.ff - p2.ff, p1.ss - p2.ss);
	// 				pair<int, int> tmp2 = mp(p4.ff - p3.ff, p4.ss - p3.ss);
	// 				if(tmp != tmp2) continue;
	// 				// p0 p1
	// 				// p3 p2

	// 				tmp = mp(p2.ff - p3.ff, p2.ss - p3.ss);
	// 				tmp2 = mp(p1.ff - p4.ff, p1.ss - p4.ss);

	// 				if(tmp != tmp2) continue;

	// 				// p1 p2
	// 				// p0 p3

	// 				can = true;
	// 			// }
	// 		}while(next_permutation(id, id+4));
	// 		// printf("%d\n", i);
	// 		if(can) ans.push_back(p[3]);
	// 	}
	// }


	printf("%d\n", (int)ans.size());
	for(set<pair<int,int> >::iterator it = ans.begin(); it != ans.end(); it++)
		printf("%d %d\n", it->ff, it->ss);
	// for(int i = 0; i < (int)ans.size(); i++)
	// 	printf("%d %d\n", ans[i].ff, ans[i].ss);



	return 0;
}