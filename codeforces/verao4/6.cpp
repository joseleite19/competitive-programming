#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

bool abre(char c){
	if(c == '[') return 1;
	if(c == '(') return 1;
	if(c == '{') return 1;
	if(c == '<') return 1;
	return 0;
}

int vai(char c){
	if(c == '[') return 0;
	if(c == '(') return 1;
	if(c == '{') return 2;
	if(c == '<') return 3;
}

int volta(char c){
	if(c == ']') return 0;
	if(c == ')') return 1;
	if(c == '}') return 2;
	if(c == '>') return 3;
}


bool fecha(char c){
	return !abre(c);
}

		multiset<int>ms[1000006];
int main(){
	file();

	int n;
	char s[1000006];
	// string s;

	scanf("%d", &n);
	// cin >> n;
	getchar();

	while(n--){
		// getline(cin, s);

		// getchar();
		scanf("%s", s);
		getchar();
		int sz = strlen(s);
		for(int i = 0; i < sz+4; i++)
			ms[i].clear();
		// printf("#%s\n", s.c_str());
		int cha = 0, col = 0, pa = 0, me = 0;
		bool ok = true;

		for(int i = 0; s[i]; i++){
			if(s[i] == '(') pa++;
			if(s[i] == ')') pa--;
			if(s[i] == '[') col++;
			if(s[i] == ']') col--;
			if(s[i] == '{') cha++;
			if(s[i] == '}') cha--;
			if(s[i] == '<') me++;
			if(s[i] == '>') me--;
			if(cha < 0 || col < 0 || pa < 0 || me < 0) ok = false;
		}
		if(cha || col || pa || me) ok = false;


		int ptr = 0;
		for(int i = 0; i < sz; i++){
			if(abre(s[i])){
				ms[ptr].insert(vai(s[i]));
			}
			else{
				int vv[4] = {0};
				int j = i;
				while(j < sz && fecha(s[j])) j++;
				j--;


				for(int k = i; k <= j; k++)
					vv[ volta(s[k]) ]++;
				i = j;

				while((vv[0] || vv[1] || vv[2] || vv[3])){

				// printf("asd\n");
					// for(int k = 0; k < 4; k++){
					// 	printf("(%d %d)", vv[k], ms[ptr].count(k));

					// }
					// for(multiset<int>::iterator it = ms[ptr].begin(); it != ms[ptr].end(); it++)
					// 	printf("##%d\n", *it);
					// printf(" \n");
					// printf("%d\n", ptr);
					if(ptr < 0 || ms[ptr].empty()){
						ok = false;
						// printf("%s\n", );
						break;
					}

					for(int k = 0; k < 4; k++){
						while(vv[k] > 0 && ms[ptr].count(k)){
							multiset<int>::iterator it = ms[ptr].find(k);
							ms[ptr].erase(it);
							vv[k]--;
						}
					}

					if(!ms[ptr].empty() && (vv[0] || vv[1] || vv[2] || vv[3])){
						ok = false;
						break;
					}
					while(ms[ptr].empty() && ptr > 0) ptr--;
				}
				ptr++;
			}
		}

		// if(ok){
		// 	stack<int> sch[4];
		// 	// stack<int> fecha[4];

		// 	for(int i = 0; i < (int)sz; i++){
		// 		if(abre(s[i])){
		// 			int j = i;
		// 			while(j < sz && abre(s[j])) j++;
		// 			j--;
		// 			int vv[4] = {0};
		// 			for(int k = i; k <= j; k++)
		// 				vv[ vai(s[k]) ]++;


		// 			for(int k = 0; k < 4; k++)
		// 				sch[k].push(vv[k]);
		// 			i = j;
		// 		}
		// 		else{
		// 			int vv[4] = {0};
					// int j = i;
					// while(j < sz && fecha(s[j])) j++;
					// j--;
					// i..j ta fechando
					
		// 			for(int k = i; k <= j; k++)
		// 				vv[ volta(s[k]) ]++;
		// 			// for(int k = 0; k < 4; k++) printf("%d %d %d\n", i, j, vv[k]);

		// 			i = j;
		// 			while((vv[0] || vv[1] || vv[2] || vv[3]) && !sch[0].empty() && !sch[1].empty() && !sch[2].empty() && !sch[3].empty()){
		// 				if(!ok) break;

		// 				for(int k = 0; k < 4; k++){
		// 					if(sch[k].empty() && vv[k]){
		// 						ok = false;
		// 					}
		// 					else if(vv[k]){
		// 						int tmp = min(vv[k], sch[k].top());
		// 						sch[k].top() -= tmp;
		// 						vv[k] -= tmp;
		// 					}
		// 				}

		// 				if(!ok) break;
		// 				bool flag = true;
		// 				for(int k = 0; k < 4; k++){
		// 					if(sch[k].top())
		// 						flag = 0;
		// 				}
		// 				if(flag){
		// 					for(int k = 0; k < 4; k++) sch[k].pop();
		// 				}
		// 				else{
		// 					for(int k = 0; k < 4; k++){
		// 						if(vv[k] && sch[k].top() == 0){
		// 							ok = false;
		// 						}
		// 					}
		// 				}
		// 			}
		// 		}
		// 	}
		// }
		// printf("%s\n", ok ? "T" : "NIL");
		printf("%s\n", (ok ? "T" : "NIL"));
	}


	return 0;
}