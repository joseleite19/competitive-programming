#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int quadrante(const pair<long long, long long> &p){
	long long px, py;

	if(p.ff == 0) return (p.ss >= 0 ? 0 : 2);
	if(p.ss == 0) return (p.ff >= 0 ? 0 : 2);

	px = p.ff/abs(p.ff);
	py = p.ss/abs(p.ss);
	if(px == 1 && py == 1) return 1;
	if(px ==-1 && py == 1) return 2;
	if(px ==-1 && py ==-1) return 3;
	if(px == 1 && py ==-1) return 0;
}

bool cmp(const pair<pair<long long, long long>, int> &p, const pair<pair<long long, long long>, int> &q){
	// int qp, qq;
	// qp = quadrante(p.ff);
	// qq = quadrante(q.ff);
	// if(qp != qq) return qp < qq;

	long long cp = p.ff.ff * q.ff.ss - q.ff.ff * p.ff.ss;
	return cp > 0;
}

int n;
pair<long long, long long> p[100005];
vector<pair<pair<long long, long long>, int> > v;

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
		scanf("%lld %lld", &p[i].ff, &p[i].ss);

	for(int i = 1; i < n; i++){
		pair<long long, long long> tmp = mp(p[i].ff - p[0].ff, p[i].ss - p[0].ss);

		if(tmp.ff == 0) continue;

		if(quadrante(tmp) == 0) v.push_back(mp(tmp, 0));
		else if(quadrante(tmp) == 2) v.push_back(mp(mp(-tmp.ff, -tmp.ss), 1));
	}

	sort(v.begin(), v.end(), cmp);
	
	int r = 0, l = 0;

	int tmpl = 0, tmpr = 0, equal = 0;
	for(int i = 1; i < n; i++){
		p[i].ff -= p[0].ff;
		p[i].ss -= p[0].ss;
		// printf("%lld %lld\n", p[i].ff, p[i].ss);

		if(p[i].ff < 0) l++;
		else if(p[i].ff > 0) r++;
		else if(p[i].ss > 0) tmpr++;
		else if(p[i].ss < 0) tmpl++;
	}

	int mx = 0, mn = 1000000000;

	mn = min(mn, 1+r);
	mx = max(mx, n-l);

	l += tmpl;
	r += tmpr;

	for(int i = 0; i < (int)v.size(); i++){
		int cntl = l, cntr = r;
		int j = i, tmp = 0;
		while(j < v.size() && !cmp(v[i], v[j]) && !cmp(v[j], v[i])){
			if(v[j].ss){
				cntr++;
				cntl--;
				l--;
			}
			else{
				cntl++;
				cntr--;
				r--;
			}
			j++;
			tmp++;
		}
		j--;
		i = j;

		mn = min(mn, 1 + r);
		mx = max(mx, n - l);
		// printf("%d %d\n", l, r);
		l = cntl;
		r = cntr;
	}
	printf("%d %d\n", mn, mx);

	return 0;
}