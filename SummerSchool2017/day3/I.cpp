#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

map<pair<int, int>, set< pair<int, int> > > m;
map<pair<int, int>, vector<pair<int, pair<int, int> > > > k;

// map<pair<int, int>, bool> vis1;
// map<pair<int, int>, bool> vis2;
// map<pair<int, int>, bool> apaga;
// map<pair<int, int>, bool> apaga2;

struct cs{
	int us, ci, ct, h, adv, show, click;

	bool operator<(const cs & o) const{
		if(h != o.h) return h < o.h;
		if(us != o.us) return us < o.us;
		if(ci != o.ci) return ci < o.ci;
		if(ct != o.ct) return ct < o.ct;
		if(adv != o.adv) return adv < o.adv;
		return show < o.show;
	}
};

int main(){

	int n, e;

	scanf("%d %d", &n, &e);

	for(int i = 0; i < n; i++){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		m[ mp(a, b) ].insert(mp(c, d));
		// if(vis1.count(mp(a, b))){
		// 	apaga[ mp(a, b) ];
		// }
		// vis1[ mp(a, b) ] = 1;
	}
	for(int i = 0; i < e; i++){
		int a, b, c, d, q;
		scanf("%d %d %d %d %d", &a, &b, &c, &d, &q);
		k[ mp(a, b) ].push_back(mp(c, mp(d, q)));
		// if(vis2.count(mp(a, b))){
		// 	apaga2[ mp(a, b) ];
		// }
		// vis2[ mp(a, b) ] = 1;
	}

	vector<cs> v;

	for(map<pair<int, int>, vector< pair<int, pair<int, int> > > >::iterator it = k.begin(); it != k.end(); it++){
		// if(apaga.count(it->ff)) continue;
		// if(apaga2.count(it->ff)) continue;
		if(!m.count(it->ff)) continue;

		vector<pair<int, pair<int, int> > > &tmp42 = it->ss;
		
		set<pair<int, int> > &tmp = m[ it->ff ];

		// printf("%d %d\n", it->ff.ff, it->ff.ss);
		for(int j = 0; j < (int)tmp42.size(); j++){
			cs tmp1, tmp2;
			tmp1.us = it->ff.ff;
			tmp1.ci = it->ff.ss;

			// printf("%d %d\n", tmp42[j].ss.ff);

			set<pair<int, int> >::iterator iit = tmp.lower_bound(mp(tmp42[j].ss.ff, 0));
			// printf("#%d %d\n", tmp42[j].ss.ff, 1);
			if(iit == tmp.begin()) continue;
			// printf("#%d %d %d %d\n", tmp42[j].ss.ff, iit->ff, iit->ss, iit == tmp.begin());
			iit--;
			// printf("##%d %d %d %d %d\n", it->ff.ff, it->ff.ss, tmp42[j].ss.ff, iit->ff, iit->ss);
			
			tmp1.ct = iit->ff;
			tmp1.h = iit->ss;
			tmp1.adv = tmp42[j].ff;
			tmp1.show = tmp42[j].ss.ff;
			tmp1.click = tmp42[j].ss.ss;

			// for(int i = 1; i < (int)tmp.size(); i++){
		
			// 	tmp2.us = it->ff.ff;
			// 	tmp2.ci = it->ff.ss;
			// 	tmp2.ct = tmp[i].ff;
			// 	tmp2.h = tmp[i].ss;
			// 	tmp2.adv = tmp42[j].ff;
			// 	tmp2.show = tmp42[j].ss.ff;
			// 	tmp2.click = tmp42[j].ss.ss;
		
			// 	if(tmp2.show > tmp2.ct){
			// 		if(tmp2.show - tmp2.ct < tmp1.show - tmp1.ct || tmp1.show <= tmp1.ct)
			// 			tmp1 = tmp2;
			// 	}
			// }

			if(tmp1.show > tmp1.ct)
				v.push_back(tmp1);
		}
	}

	sort(v.begin(), v.end());

	printf("%d\n", (int)v.size());
	for(int i = 0; i < (int)v.size(); i++)
		printf("%d %d %d %d %d %d %d\n", v[i].us, v[i].ci, v[i].ct, v[i].h, v[i].adv, v[i].show, v[i].click);


	return 0;
}