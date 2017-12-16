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

const int N = 100005;

char s[N];
int n;

char *f(int x){
	n = 0;
	while(x){
		printf("#%d\n", x % 27);
		s[n++] = (x % 27)+'A'-1;
		x /= 27;
	}
	reverse(s, s+n);
	s[n] = 0;
	return s;
}

int back(char *t){
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans = (ans * 26) + s[i]-'A'+1;
	}

	return ans;
}

int main(){
	map<string, int> go;
	map<int, string> bk;

	/*int k = 1;
	string t = "Q";

	for(int i = 'A'; i <= 'Z'; i++){
		t[0] = i;
		go[t] = k, bk[k] = t, k++;
	}
	printf("size 1 < %d\n", k);

	t = "AA";
	fore(a, 'A', 'Z') fore(b, 'A', 'Z'){
		t[0] = a, t[1] = b, s[2] = 0;
		go[t] = k, bk[k] = t, k++;
	}
	printf("size 2 < %d\n", k);

	t = "AAA";
	fore(a, 'A', 'Z') fore(b, 'A', 'Z') fore(c, 'A', 'Z'){
		t[0] = a, t[1] = b, t[2] = c, s[3] = 0;
		go[t] = k, bk[k] = t, k++;
	}
	printf("size 3 < %d\n", k);

	t = "AAAA";
	fore(a, 'A', 'Z') fore(b, 'A', 'Z') fore(c, 'A', 'Z') fore(d, 'A', 'Z'){
		t[0] = a, t[1] = b, t[2] = c, t[3] = d,s[4] = 0;
		go[t] = k, bk[k] = t, k++;
	}
	printf("size 4 < %d\n", k);
	
	t = "AAAAA";
	fore(a, 'A', 'Z') fore(b, 'A', 'Z') fore(c, 'A', 'Z')
		fore(d, 'A', 'Z') fore(e, 'A', 'Z'){
		t[0] = a, t[1] = b, t[2] = c, t[3] = d,s[4] = 0;
		go[t] = k, bk[k] = t, k++;
		if(k >= 1000000) goto out;
	}
out:
	printf("size 5 < %d\n", k);

	printf("%d\n", k);


	return 0; */
	int tc;

	scanf("%d", &tc);

	while(tc--){
		scanf(" %s", s);
		int x, y;

		if(sscanf(s, "R%dC%d", &x, &y) == 2){
			printf("%s%d\n", f(y), x);
		}
		else{
			n = strlen(s);
			int pot = 1; x = 0;
			while(s[n-1] >= '0' && s[n-1] <= '9'){
				x += (s[n-1] - '0') * pot;
				pot *= 10;
				n--;
			}
			printf("R%dC%d\n", x, back(s));
		}
	}



    return 0;
}
