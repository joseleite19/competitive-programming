#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int normal[200];
int inv[200];

char s[100005];

string doit(vector<pair<int, int> > global){
	string ret = "";

	for(int i = 0; i < global.size(); i++){
		if(global[i].ff == global[i].ss) ret += global[i].ff;
		else if(global[i].ff+1 == global[i].ss){
			ret += global[i].ff;
			ret += global[i].ss;
		}
		else{
			if(global[i].ff == '0') global[i].ff = '!';
			if(global[i].ff == 'A') global[i].ff = ':';
			if(global[i].ff == 'a') global[i].ff = '[';
			ret += global[i].ff;
			ret += '-';
			ret += global[i].ss;
		}
	}
	return ret;
}

int main(){

	scanf("%[^\n]", s);
	int n = strlen(s);

	for(int i = 0; i < 200; i++) inv[i] = 1;

	for(int i = 0; i < n; i++)
		normal[ s[i] ] = 1, inv[ s[i] ] = 0;

	vector<pair<int, int> > es, esi;
	vector<pair<int, int> > num, numi;
	vector<pair<int, int> > up, upi;
	vector<pair<int, int> > lo, loi;

	if(normal[' ']) es.push_back(mp(' ', ' '));
	if(inv[' ']) esi.push_back(mp(' ', ' '));

	for(int i = '0'; i <= '9'; i++){
		int j = i;
		if(!normal[i]) continue;
		while(j <= '9' && normal[j]) j++;
		j--;
		num.push_back(mp(i, j));
		i = j;
	}
	for(int i = '0'; i <= '9'; i++){
		int j = i;
		if(!inv[i]) continue;
		while(j <= '9' && inv[j]) j++;
		j--;
		numi.push_back(mp(i, j));
		i = j;
	}

	for(int i = 'a'; i <= 'z'; i++){
		int j = i;
		if(!normal[i]) continue;
		while(j <= 'z' && normal[j]) j++;
		j--;
		lo.push_back(mp(i, j));
		i = j;
	}

	for(int i = 'A'; i <= 'Z'; i++){
		int j = i;
		if(!normal[i]) continue;
		while(j <= 'Z' && normal[j]) j++;
		j--;
		up.push_back(mp(i, j));
		i = j;
	}

	for(int i = 'a'; i <= 'z'; i++){
		int j = i;
		if(!inv[i]) continue;
		while(j <= 'z' && inv[j]) j++;
		j--;
		loi.push_back(mp(i, j));
		i = j;
	}

	for(int i = 'A'; i <= 'Z'; i++){
		int j = i;
		if(!inv[i]) continue;
		while(j <= 'Z' && inv[j]) j++;
		j--;
		upi.push_back(mp(i, j));
		i = j;
	}

	if(normal[' '] && normal['0']){
		int j = 0;
		for(j = 0; j < num.size(); j++)
			if(num[j].ff == '0')
				break;
		if(num[j].ss > '0'){
			es.pop_back();
			int tmp = num[j].ss;
			num.erase(num.begin()+j);
			num.push_back(mp(' ', tmp));
		}
	}
	if(normal['9'] && normal['A']){
		int j = 0;
		for(j = 0; j < up.size(); j++)
			if(up[j].ff == 'A')
				break;
		if(num.back().ff < '9' || up[j].ss > 'A'){
			int tmp = up[j].ss, tmpinf = num.back().ff;
			num.pop_back();
			up.erase(up.begin()+j);
			up.push_back(mp(tmpinf, tmp));
		}
	}
	if(normal['Z'] && normal['a']){
		int j = 0;
		for(j = 0; j < lo.size(); j++)
			if(lo[j].ff == 'a')
				break;
		if(up.back().ff < 'Z' || lo[j].ss > 'a'){
			int tmp = lo[j].ss, tmpinf = up.back().ff;
			up.pop_back();
			lo.erase(lo.begin()+j);
			lo.push_back(mp(tmpinf, tmp));
		}
	}

	if(inv[' '] && inv['0']){
		int j = 0;
		for(j = 0; j < numi.size(); j++)
			if(numi[j].ff == '0')
				break;
		if(numi[j].ss > '0'){
			esi.pop_back();
			int tmp = numi[j].ss;
			numi.erase(numi.begin()+j);
			numi.push_back(mp(' ', tmp));
		}

	}
	if(inv['9'] && inv['A']){
		int j = 0;
		for(j = 0; j < upi.size(); j++)
			if(upi[j].ff == 'A')
				break;
		if(numi.back().ff < '9' || upi[j].ss > 'A'){
			int tmp = upi[j].ss, tmpinf = numi.back().ff;
			numi.pop_back();
			upi.erase(upi.begin()+j);
			upi.push_back(mp(tmpinf, tmp));
		}

	}
	if(inv['Z'] && inv['a']){
		int j = 0;
		for(j = 0; j < loi.size(); j++)
			if(loi[j].ff == 'a')
				break;
		if(upi.back().ff < 'Z' || loi[j].ss > 'a'){
			int tmp = loi[j].ss, tmpinf = upi.back().ff;
			upi.pop_back();
			loi.erase(loi.begin()+j);
			loi.push_back(mp(tmpinf, tmp));
		}
	}

	vector<pair<int, int> > global, globali;
	for(int i = 0; i < es.size(); i++) global.push_back(es[i]);
	for(int i = 0; i < num.size(); i++) global.push_back(num[i]);
	for(int i = 0; i < up.size(); i++) global.push_back(up[i]);
	for(int i = 0; i < lo.size(); i++) global.push_back(lo[i]);

	for(int i = 0; i < esi.size(); i++) globali.push_back(esi[i]);
	for(int i = 0; i < numi.size(); i++) globali.push_back(numi[i]);
	for(int i = 0; i < upi.size(); i++) globali.push_back(upi[i]);
	for(int i = 0; i < loi.size(); i++) globali.push_back(loi[i]);

	int tot = 0, toti = 1;

	for(int i = 0; i < global.size(); i++)
		tot += min(3, global[i].ss - global[i].ff + 1);	

	for(int i = 0; i < globali.size(); i++)
		toti += min(3, globali[i].ss - globali[i].ff + 1);	

	string ans = doit(global);
	if(toti == 1) toti++;

	if(toti < tot){
		ans = '^';
		ans += doit(globali);
		if(ans == "^") ans = "^!";
	}
	else if(toti == tot){
		string tmp = doit(globali);
		if(tmp == "") tmp = "!";
		ans = min(ans, "^" + tmp);
	}	

	printf("%%[%s]\n", ans.c_str());


	return 0;
}