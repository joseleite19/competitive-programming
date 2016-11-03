#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

int main(){
	int n;

	vector<pair<int,pair<int, int> > > v;

	map<pair<int,int>, vector<pair<int, int> > > m;

	scanf("%d", &n);

	int a, b, c;
	int vet[3];
	for(int i = 0; i < n; i++){
		
		for(int j = 0; j < 3; j++)
			scanf("%d", vet+j);

		sort(vet, vet+3);

		m[ mp(vet[0], vet[1]) ].push_back(mp(vet[2], i));
		m[ mp(vet[1], vet[2]) ].push_back(mp(vet[0], i));
		m[ mp(vet[0], vet[2]) ].push_back(mp(vet[1], i));
	}

	int ans = 0;
	vet[0] = vet[1] = 0;
	int qnt = 0;
	for(auto &x : m){

		sort(x.ss.begin(), x.ss.end(), greater<pair<int,int> >());
		auto last = std::unique(x.ss.begin(), x.ss.end());
    	x.ss.erase(last, x.ss.end());

		if(x.ss.size() == 1){
			int tmp = min(min(x.ff.ff, x.ff.ss), x.ss[0].ff);
			if(tmp > ans){
				vet[0] = x.ss[0].ss+1;
				ans = tmp;
				qnt = 1;
			}
		}
		else if(x.ss.size() >= 2){

			int tmp = min(min(x.ff.ff, x.ff.ss), x.ss[0].ff + x.ss[1].ff);
			if(tmp > ans){
				vet[0] = x.ss[0].ss+1;
				vet[1] = x.ss[1].ss+1;
				ans = tmp;
				qnt = 2;
			}
		}
	}
	if(qnt == 2 && vet[0] == vet[1]) qnt--;

	printf("%d\n", qnt);
	for(int i = 0; i < qnt; i++)
		printf(" %d", vet[i]);
	printf("\n");

}