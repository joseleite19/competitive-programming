#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = int(a); i < int(b); i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define debug(x) cout << #x << " = " << x << endl
#define ford(i, a, b) for(int i = a; i >= b; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MAX = 2e5 + 5;
int I[MAX], S[MAX], V[MAX], D[MAX];
int guy[MAX];
vector<int> skills[MAX];
vector<int> pos[4];
int n, x0, a, b;

inline int eval(char c) {
	if(c == 'I') {
		return 0;
	}
	else if(c == 'S') {
		return 1;
	}
	else if(c == 'V') {
		return 2;
	}
	return 3;
}

int main(){
	int kase = 1;
	int t;
	scanf("%d%*c", &t);
	while(t--) {
		fori(i, 0, 4) {
			pos[i].clear();
		}
		scanf("%d%*c", &n);
		fori(i, 1, n + 1) {
			skills[i].clear();
		}
		scanf("%d %d %d%*c", &x0, &a, &b);
		set<ii> alive;
		fori(i, 1, 2 * n) {
			if(i & 1) {
				scanf("%d%*c", &guy[i]);
				alive.emplace(i, guy[i]);
			}
			else {
				char c;
				scanf("%c%*c", &c);
				pos[eval(c)].push_back(i);
			}
		}
		vector<int> order;
		fori(i, 0, 4) {
			char c;
			scanf("%c%*c", &c);
			order.push_back(eval(c));
		}
		int last_x = x0;
		fori(i, 1, n + 1) {
			fori(j, 0, 4) {
				int cur_x = (a * last_x + b) % 101;
				skills[i].push_back(cur_x);
				last_x = cur_x;
			}
		}
		fori(i, 0, order.size()) {
			int v = order[i];
			fori(j, 0, pos[v].size()) {
				auto rgt_it = alive.lower_bound(ii(pos[v][j], 0));
				auto lft_it = prev(rgt_it);
				int lft = (*lft_it).second;
				int rgt = (*rgt_it).second;
				if(skills[lft][v] > skills[rgt][v]) {
					alive.erase(rgt_it);
				}
				else if(skills[rgt][v] > skills[lft][v]) {
					alive.erase(lft_it);
				}
				else if(rgt > lft) {
					alive.erase(rgt_it);
				}
				else {
					alive.erase(lft_it);
				}
			}
		}
		printf("Caso #%d: %d\n", kase++, (*alive.begin()).second);
	}

    return 0;
}
