#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

map<int, vector<int> > soma, sub, vert, hor;
int xx, yy, n;

bool bishop(int x, int y){
	int minX, maxX;
	minX = min(xx, x);
	maxX = max(xx, x);
	if(xx + yy == x + y){
		vector<int> &v = soma[ x+y ];
		auto it = lower_bound(v.begin(), v.end(), minX);
		auto it2 = lower_bound(v.begin(), v.end(), maxX);
		it++;
		it2--;
		if(*it > *it2) return true;
	}
	if(xx - yy == x - y){
		vector<int> &v1 = sub[ x-y ];
		auto it = lower_bound(v1.begin(), v1.end(), minX);
		auto it2 = lower_bound(v1.begin(), v1.end(), maxX);
		it++;
		it2--;
		if(*it > *it2) return true;
	}
	return false;
}

bool rook(int x, int y){
	int minX, maxX, minY, maxY;
	minX = min(xx, x);
	maxX = max(xx, x);
	minY = min(yy, y);
	maxY = max(yy, y);

	if(x == xx){
		vector<int> &v = vert[x];
		auto it = lower_bound(v.begin(), v.end(), minY);
		auto it2 = lower_bound(v.begin(), v.end(), maxY);
		it++;
		it2--;
		if(*it > *it2) return true;
	}
	
	if(y == yy){
		vector<int> &v1 = hor[y];
		auto it = lower_bound(v1.begin(), v1.end(), minX);
		auto it2 = lower_bound(v1.begin(), v1.end(), maxX);
		it++;
		it2--;
		if(*it > *it2) return true;
	}
	return false;
}

int main(){

	char c;

	pair<char, pair<int, int> > piece[500005];

	scanf("%d %d %d", &n, &xx, &yy);


		
		soma[ xx+yy ].push_back(xx);
		sub[ xx-yy ].push_back(xx);
		hor[yy].push_back(xx);
		vert[xx].push_back(yy);

	for(int i = 0; i < n; i++){
		scanf(" %c %d %d", &piece[i].ff, &piece[i].ss.ff, &piece[i].ss.ss);

		int x = piece[i].ss.ff;
		int y = piece[i].ss.ss;
		soma[ x+y ].push_back(x);
		sub[ x-y ].push_back(x);
		hor[y].push_back(x);
		vert[x].push_back(y);
	}

	for(pair<const int, vector<int> > & v : soma) sort(v.ss.begin(), v.ss.end());
	for(pair<const int, vector<int> > & v : sub) sort(v.ss.begin(), v.ss.end());
	for(pair<const int, vector<int> > & v : vert) sort(v.ss.begin(), v.ss.end());
	for(pair<const int, vector<int> > & v : hor) sort(v.ss.begin(), v.ss.end());

	bool check = false;

	for(int i = 0; i < n && !check; i++){
		int x = piece[i].ss.ff;
		int y = piece[i].ss.ss;
		c = piece[i].ff;
		if(c == 'B'){
			check = bishop(x, y);
		} 
		else if(c == 'R'){
			check = rook(x, y);
		}
		else{
			check = bishop(x, y) || rook(x, y);
		}
	}

	printf("%s\n", check ? "YES" : "NO");

	return 0;
}