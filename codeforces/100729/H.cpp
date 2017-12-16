#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

char card[15][5];

int v[15];

int dp[1 << 15];

int n = 13;

vector<vector<vector<int> > > hack(1 << 15);
vector<vector<vector<int> > > hackzao(1 << 15);
// FFF
// 1111 1111 1111
int f(int bitmask){
	if(bitmask == (1 << 13) - 1) return 0;
	if(dp[bitmask] != -1) return dp[bitmask];
	// printf("asd %04x %d %d\n", bitmask, bitmask, 1 << 13);

	vector<pair<int, int> > vp;
	vector<pair<int, pair<int, int> > > vpp;

	int ret = 15, newb;

	vector<int> tmp;

	for(int i = 0; i < n; i++){
		if(bitmask & (1 << i)) continue;

		newb = bitmask | (1 << i);
		// printf("#qwe %d\n", newb);
		if(ret > 1 + f(newb)){
			ret = 1 + f(newb);
		// printf(".qwe %d\n", newb);
			hack[bitmask] = hack[newb];
			tmp = vector<int>();
			tmp.push_back(i);
			hack[bitmask].push_back(tmp);
		}

		for(int j = i+1; j < n; j++){
			if(bitmask & (1 << j)) continue;
			if(v[i] != v[j]) continue;

			newb = bitmask | (1 << i) | (1 << j);
			
			if(ret > 1 + f(newb)){
				ret = 1 + f(newb);
				hack[bitmask] = hack[newb];
				tmp = vector<int>();
				tmp.push_back(i);
				tmp.push_back(j);
				hack[bitmask].push_back(tmp);
			}

			vp.push_back(mp(i, j));

			for(int k = j+1; k < n; k++){
				if(bitmask & (1 << k)) continue;
				if(v[i] != v[k]) continue;
				
				newb = bitmask | (1 << i) | (1 << j) | (1 << k);
				if(ret > 1 + f(newb)){
					ret = 1 + f(newb);
					hack[bitmask] = hack[newb];
					tmp = vector<int>();
					tmp.push_back(i);
					tmp.push_back(j);
					tmp.push_back(k);
					hack[bitmask].push_back(tmp);
				}
				vpp.push_back(mp(i, mp(j, k)));

				for(int q = k+1; q < n; q++){
					if(bitmask & (1 << q)) continue;
					if(v[i] != v[q]) continue;
					
					newb = bitmask | (1 << i) | (1 << j) | (1 << k) | (1 << q);
					if(ret > 1 + f(newb)){
						ret = 1 + f(newb);
						hack[bitmask] = hack[newb];
						tmp = vector<int>();
						tmp.push_back(i);
						tmp.push_back(j);
						tmp.push_back(k);
						tmp.push_back(q);
						hack[bitmask].push_back(tmp);
					}
				}
			}
		}
	}

	for(int i = 0; i < (int)vp.size(); i++){
		for(int j = 0; j < (int)vpp.size(); j++){
			if(v[ vp[i].ff ] == v[ vpp[j].ff ]) continue;
			
			// printf("(%d %d) (%d %d %d)\n", v[ vp[i].ff ], v[ vp[i].ss ], v[ vpp[j].ff ], v[ vpp[j].ss.ff ], v[ vpp[j].ss.ss ]);
			
			newb = bitmask | (1 << vp[i].ff) | (1 << vp[i].ss) | (1 << vpp[j].ff) | (1 << vpp[j].ss.ff) | (1 << vpp[j].ss.ss);
			if(ret > 1 + f(newb)){
				ret = 1 + f(newb);
				hack[bitmask] = hack[newb];
				tmp = vector<int>();
				tmp.push_back(vp[i].ff);
				tmp.push_back(vp[i].ss);
				tmp.push_back(vpp[j].ff);
				tmp.push_back(vpp[j].ss.ff);
				tmp.push_back(vpp[j].ss.ss);
				hack[bitmask].push_back(tmp);
			}
		}
	}

	// 1 2 3 4 5 6 7 8 9
	// xxxxxxxx0 1 2 3 4

	for(int i = 0; i < (int)hackzao[bitmask].size(); i++){
		int newb = bitmask;
		tmp = vector<int>();
		for(int j = 0; j < (int)hackzao[bitmask][i].size(); j++){
			newb |= (1 << hackzao[bitmask][i][j]);
			tmp.push_back(hackzao[bitmask][i][j]);
		}
		if(ret > 1 + f(newb)){
			ret = 1 + f(newb);
			hack[bitmask] = hack[newb];
			hack[bitmask].push_back(tmp);
		}
	}

	// for(int tam = 5; tam <= 13; tam++){
	// 	for(int i = 0; i < 13 - tam + 1; i++){
	// 		if(bitmask & (1 << i)) continue;
	// 		int can = 1;
	// 		vector<int> id;
	// 		id.push_back(i);

	// 		int tmp = i+1;
	// 		for(int j = 1; j < tam; j++){
	// 			while(tmp < n && (v[ id[ id.size()-1 ] ] + 1 != v[tmp] || (bitmask && (1 << tmp))))
	// 				tmp++;
	// 			if(tmp == n){
	// 				can = 0;
	// 				break;
	// 			}
	// 			id.push_back(tmp);
	// 		}

	// 		if(!can || id.size() < tam) continue;

	// 		newb = bitmask;
	// 		for(int j = 0; j < tam; j++){
	// 			newb |= (1 << (id[j]));
	// 		}
	// // printf("..qwe %d\n", newb);
	// 		if(ret > 1 + f(newb)){
	// 			ret = 1 + f(newb);
	// 			hack[bitmask] = hack[newb];
	// 			hack[bitmask].push_back(id);
	// 		}
	// 	}
	// }

	return dp[bitmask] = ret;
}

int f(char c){
	if(c >= '2' && c <= '9') return c - '0';
	else if(c == 'T') return 10;
	else if(c == 'J') return 11;
	else if(c == 'Q') return 12;
	else if(c == 'K') return 13;
	else if(c == 'A') return 14;
	return 0;
}

int main(){
	int t;

	scanf("%d", &t);

	while(t--){
		for(int i = 0; i < 13; i++)
			scanf(" %s", card[i]);

		for(int i = 0 ; i < 13; i++){
			for(int j = i+1; j < 13; j++){
				if(f(card[i][0]) > f(card[j][0])){
					char s[5];
					strcpy(s, card[i]);
					strcpy(card[i], card[j]);
					strcpy(card[j], s);
				}
			}
		}
		// for(int i = 0 ; i < 13; i++){
		// 	printf("%s\n", card[i]);
		// }


		for(int i = 0; i < 13; i++)
			v[i] = f(card[i][0]);

		hackzao.assign(1 << 13, vector<vector<int> >());
		for(int i = 0; i < (1 << 13); i++){
			if(__builtin_popcount(i) < 5) continue;
			vector<int> tmp;
			bool can = 0;
			for(int j = 0; j < 13; j++)
				if(i & (1 << j))
					tmp.push_back(j);

			for(int j = 1; j < tmp.size(); j++)
				if(tmp[j] != 1 + tmp[j-1])
					can = 0;
			if(!can) continue;
			hackzao[i].push_back(tmp);
		}
		
		for(int i = 0; i < (1 << 13); i++){
			if(__builtin_popcount(i) < 5) continue;
			
			for(int j = 0; j < 13; j++){
				if(!(i & (1 << j))) continue;
				std::copy(hackzao[i & ~(1 << j)].begin(), hackzao[i & ~(1 << j)].end(), std::back_inserter(hackzao[i]));
			}
		}
		

		memset(dp, -1, sizeof dp);
		printf("%d\n", f(0));
		for(int i = 0; i < (int)hack[0].size(); i++){
			for(int j = 0; j < (int)hack[0][i].size(); j++){
				printf("%s ", card[ hack[0][i][j] ]);
			}
			printf("\n");
		}
	}

	return 0;
}