#include <bits/stdc++.h>

using namespace std;

char s[300005];

int main(){

	scanf(" %s", s);
	int n = strlen(s);

	multiset<char> oleg;

	for(int i = 0; i < n; i++)
		oleg.insert(s[i]);

	scanf(" %s", s);

	multiset<char> igor;

	for(int i = 0; i < n; i++)
		igor.insert(s[i]);

	memset(s, '?', n);

	int pl = 0, pr = n-1;

	while(igor.size() > n/2){
		multiset<char>::iterator it = igor.begin();
		igor.erase(it);
	}

	while(oleg.size() > (n+1) / 2){
		multiset<char>::iterator it = oleg.end();
		oleg.erase(--it);
	}

	for(int i = 0; i < n; i++){
		multiset<char>::iterator it;
		if(i & 1){ //igor plays
			if((pr - pl >= 1) && *igor.rbegin() <= *oleg.begin()){
				s[pr--] = *igor.begin();
				igor.erase(igor.begin());
			}
			else{
				it = igor.end();
				it--;
				s[pl++] = *it;
				igor.erase(it);
			}
		}
		else{ //oleg plays
			if((pr - pl >= 1) && *oleg.begin() >= *igor.rbegin()){
				it = oleg.end();
				it--;
				s[pr--] = *it;
				oleg.erase(it);
			}
			else{
				s[pl++] = *oleg.begin();
				oleg.erase(oleg.begin());
			}
		}
	}

	printf("%s\n", s);

	return 0;
}