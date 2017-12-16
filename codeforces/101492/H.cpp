#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

	int xi,yi;
	int xf,yf;

	char atual;

	scanf("%d %d %c", &xi, &yi, &atual);

	scanf("%d %d", &xf, &yf);

	bool andei1,andei2;

	andei2 = andei1 = false;

	char coord1,coord2;

	int anda1,anda2;

	if(yi - yf < 0){
		coord1 = 'N';
		anda1 = yf - yi;
	}
	else{
		coord1 = 'S';
		anda1 = yi - yf;
	}

	if(xi - xf < 0){
		coord2 = 'E';
		anda2 = xf - xi;
	}
	else{
		coord2 = 'O';
		anda2 = xi - xf;
	}

	if(anda2 == 0) andei2 = true;
	if(anda1 == 0) andei1 = true;

	vector <string> resp;

	for(int i = 0; i < 6; i++){

		if(i == 0){

			if(andei1 == false){
				if(atual == coord1){
					andei1 = true;
					string s = "A ";
					s += to_string(anda1);
					resp.push_back(s);
				}
			}
			if(andei2 == false){
				if(atual == coord2){
					andei2 = true;
					string s = "A ";
					s += to_string(anda2);
					resp.push_back(s);

				}
			}
		}
		else{

			if(andei2 and andei1) break;

			if(atual == 'N') atual = 'E';
			else if(atual == 'E') atual = 'S';
			else if(atual == 'S') atual = 'O';
			else if(atual == 'O') atual = 'N';
			
			resp.push_back("D");

			if(andei1 == false){
				if(atual == coord1){
					andei1 = true;
					string s = "A ";
					s += to_string(anda1);
					resp.push_back(s);
				}
			}
			if(andei2 == false){
				if(atual == coord2){
					andei2 = true;
					string s = "A ";
					s += to_string(anda2);
					resp.push_back(s);

				}
			}
			if(andei2 and andei1) break;
		}
	}

	printf("%d\n",resp.size());

	for(string x: resp){
		printf("%s\n",x.c_str() );
	}

    return 0;
}
