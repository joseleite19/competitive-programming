#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

void file(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

char s[1003];
char buff[1003];
int tem,ap;
vector<char> aux;
char c[1003][1003];

int main(){
	int i = 0;
	while(scanf(" %s", c[i]) == 1)	i++;
	for(int j = 0; j < i; j++){
		if(c[j][0] != '*' && c[j][0] != '#'){
			if(tem){
				if(ap){

					for(int k = aux.size()-1; k >= 0; k--){
						printf("%s\n",aux[k] == '*' ? "</ul>" : aux[k] == "#" ? "</ol>" : "</li>");
						aux.pop_back();
					}
				}
					printf("%s\n", buff);
				tem = 0;
				buff[0] = 0;
			}
			printf("%s\n", c[j]);
			continue;
		}

		
	}
	

	vector<int> t;
	while(scanf(" %s", s) == 1){
		if(s[0] != '*' && s[0] != '#'){
			if(tem){
				printf("%s\n", buff);
				tem = 0;
				buff[0] = 0;
			}
			printf("%s\n", s);
			continue;
		}
		if(!tem){
			strcpy(buff, s);
			tem = 1;
			continue;
		}

		if(s[0] != buff[0]){
			strcpy(buff, s);
			tem = 1;
			continue;
		}




	}
	if(tem){
		printf("%s\n", buff);
	}




	return 0;
}