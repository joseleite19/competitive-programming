#include <bits/stdc++.h>

#define fore(i, a, b) for(int i = a; i < b; i++)
#define forn(i, n) fore(i, 0, n)
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define ford(i, n) for(int i = n - 1; i >= 0; i--)

using namespace std;

typedef long long ll;

const int N = 200005;

int n, m;
char s[N];
int ft[N];

void add(int x, int v){
		for(; x < N; x += x & -x)
					ft[x] += v;
}

int sum(int x){
		int ans = 0;
			for(; x > 0; x -= x & -x)
						ans += ft[x];
				return ans;
}

set<pair<int, int> > t[333];

int rem[N];

int main(){

		scanf("%d %d %s", &n, &m, s+1);

			fore(i, 1, n+1){
						add(i, 1);
								t[ s[i] ].emplace(i, i);
									}

				int a, b;
					char c;
						while(m--){
									scanf("%d %d %c", &a, &b, &c);

											set<pair<int, int> >::iterator it;

													pair<int, int> tmp = *t[c].lower_bound(mp(a, 0));
															int d = 0;
																	vector<int> ids;
																			while(t[c].lower_bound(tmp) != t[c].end()){
																				printf("..%d %d..\n", tmp.ff, tmp.ss);
																							t[c].erase(tmp);
																										tmp.ff = sum(tmp.ss);
																													t[c].insert(tmp);
																																if(tmp.ff+d > b) break;
																																			if(tmp.ff+d >= a){
																																								t[c].erase(tmp);
																																												ids.pb(tmp.ss);
																																																rem[tmp.ss] = 1;
																																																			}
																																						if(t[c].upper_bound(tmp) == t[c].end()) break;
																																									tmp = *t[c].upper_bound(tmp);
																																												// printf("%d\n",tmp.ff);
																																											}
																					for(int w : ids) add(w, -1);
																					for(auto w : t[c]) printf("(%d %d) ", w.ff, w.ss);
																					printf("\n");
																						}

							fore(i, 1, n+1) if(!rem[i])
										printf("%c", s[i]);
								printf("\n");


								    return 0;
}
