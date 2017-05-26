#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

set<vector<int> > vis;

vector<pair<int, int> > moves[10];

bool finish(const vector <int>& v){
	if(v[0] != 1) return false;
	if(v[1] != 2) return false;
	if(v[2] != 3) return false;
	if(v[3] != 8) return false;
	if(v[4] != 0) return false;
	if(v[5] != 4) return false;
	if(v[6] != 7) return false;
	if(v[7] != 6) return false;
	if(v[8] != 5) return false;
	return true;
}

vector<int> resp;
int cnt;

int vet[1000006], ptr;

set<vector<int> > ss;

bool dfs(vector<int>& u){
	cnt++;
	if(ss.count(u)) return false;

	if(finish(u)){
		return true;
	}

	ss.insert(u);
	int t = 0;
	for(int i = 0; i < (int)u.size(); i++)
		if(!u[i])
			t = i;

	cnt += moves[t].size();
	for(int k = 0; k < (int)moves[t].size(); k++){
		swap(u[moves[t][k].ff], u[t]);
		// resp.push_back(moves[t][k].ss);
		vet[ptr++] = moves[t][k].ss;

		if(dfs(u)) return true;

		ptr--;

		// resp.pop_back();
		swap(u[moves[t][k].ff], u[t]);
	}


	return false;
}

// 0 1 2
// 3 4 5
// 6 7 8

//   0
// 1 x 2
//   3

int main(){

	moves[0].push_back(mp(1, 2));
	moves[0].push_back(mp(3, 3));
	moves[1].push_back(mp(0, 1));
	moves[1].push_back(mp(2, 2));
	moves[1].push_back(mp(4, 3));
	moves[2].push_back(mp(1, 1));
	moves[2].push_back(mp(5, 3));
	moves[3].push_back(mp(0, 0));
	moves[3].push_back(mp(4, 2));
	moves[3].push_back(mp(6, 3));
	moves[4].push_back(mp(1, 0));
	moves[4].push_back(mp(3, 1));
	moves[4].push_back(mp(5, 2));
	moves[4].push_back(mp(7, 3));
	moves[5].push_back(mp(2, 0));
	moves[5].push_back(mp(4, 1));
	moves[5].push_back(mp(8, 3));
	moves[6].push_back(mp(3, 0));
	moves[6].push_back(mp(7, 2));
	moves[7].push_back(mp(4, 0));
	moves[7].push_back(mp(6, 1));
	moves[7].push_back(mp(8, 2));
	moves[8].push_back(mp(5, 0));
	moves[8].push_back(mp(7, 1));

	vector<int> input = {0, 1, 3,
						 5, 7, 2,
						 4, 8, 6};

	// vector<int> input = {1, 2, 3,
	// 					 8, 6, 4,
	// 					 7, 0, 5};

	if(dfs(input)){
		printf("Answer found, moves are:\n");
		for(int i = 0; i < ptr; i++)
			printf("%d ", vet[i]);
		printf("\n");
	}
	else printf("Answer not found!\n");

	return 0;
}
