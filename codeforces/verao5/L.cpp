#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back

using namespace std;

char s[5005], t[5005];
int n, m;

int main(){

	scanf(" %s %s", s, t);

	int n = strlen(s), m = strlen(t);

	int p1, p2;

	p1 = p2 = 0;

	bool ok = true;

	char last = '0';
	char last2 = '0';
	while(1){
		if(p2 == m && p1 != n){
			ok = false;
			// printf("asd\n");
			break;
		}
		if(p2 == m && p1 == n) break;

		if(s[p1] == t[p2]){
			if(last != t[p2]){
				if(last != last2){
					last2 = last;
				}
			}
			last = s[p1];
			p1++;
			p2++;
		}
		else{
			if(p1 == 0 || ((last2 == t[p2] || last2 == '0') && last == t[p2])){
				ok = false;
				// printf("asd1\n");
				break;
			}
			if(last != t[p2]){
				if(last != last2){
					last2 = last;
				}
			}
			last = t[p2];
			p2++;
		}
	}

	printf("%s\n", ok ? "Yes" : "No");


	return 0;
}