#include <bits/stdc++.h>

using namespace std;

class eight_queen{

	int used[8];
	int ans[8];
	int used2[15];
	int used3[32];

	int cnt;

	set<vector<int> > s;

	bool ready;

	void queen(int i){
		if(i == 8){
			vector<int> tmp;

			printf("Answer %d:\n", ++cnt);
			for(int i = 0; i < 8; i++){
				for(int j = 0; j < 8; j++)
					printf(" %c", ans[i] == j ? '*' : '-');
				printf("\n");
			}
			for(int i = 0; i < 8; i++)
				tmp.push_back(ans[i]);
			s.insert(tmp);
		}
		else{
			for(int j = 0; j < 8; j++){
				if(!used[j] && !used2[i + j] && !used3[16+i-j]){
					ans[i] = j;
					
					used[j] = 1;
					used2[i + j] = 1;
					used3[16+i-j] = 1;
					queen(i+1);
					used[j] = 0;
					used2[i + j] = 0;
					used3[16+i-j] = 0;
				}
			}
		}
	}
public:

	eight_queen(){
		memset(used, 0, sizeof used);
		memset(used2, 0, sizeof used2);
		memset(used3, 0, sizeof used3);
		cnt = 0;
		ready = 0;
	}

	void run(){
		queen(0);
		ready = 1;
	}

	set<vector<int> > get_answer(){
		if(!ready) return set<vector<int> > ();

		return s;
	}
};

int main(){

	eight_queen q;

	q.run();

	return 0;
}
