#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;
int n, v1[400005], v[400005], t, size;

int main(){
	char s[200005];

	scanf("%d %d %s", &n, &t, s);

	int tam = strlen(s), i, j;

	for(i = tam-1, j = 0; i >= 0 && s[i] != '.'; i--, j++){
		v[j] = s[i]-'0';
	}
	size = j;

	for(i--, j = 0; i >= 0; i--, j++){
		v1[j] = s[i]-'0';
	}

	int carry = 0;
	while(1){
		carry = 0;
		for(i = size-1; i >= 0; i--){
			if(v[i] >= 5 && t){
				v[i] = -1;
				t--;
				carry = 1;
				break;
			}
		}
		if(i < 0) break;
		for(i++; carry && i <= size; i++){
			v[i] += carry;
			carry = 0;
			if(v[i] >= 10){
				v[i] -= 10;
				carry = 1;
			}
		}
		if(!t) break;
	}

	for(i = size-1; i >= 0; i--)
		if(v[i] == -1) break;
	
	for(; i >= 0; i--)
		v[i] = 0;

	carry = v[size];
	for(i = 0; i < 2*n - size; i++){
		v1[i] += carry;
		carry = 0;
		if(v1[i] >= 10){
			v1[i] -= 10;
			carry++;
		}
	}

	int limit = 0;

	for(int i = 0; i <= 2*n; i++)
		if(v1[i])
			limit = i;

	for(i = limit; i >= 0; i--)
		printf("%d", v1[i]);

	limit = -1;
	for(int i = size-1; i >= 0; i--)
		if(v[i])
			limit = i;
	if(limit != -1){
		printf(".");
		for(i = size-1; i >= limit; i--)
			printf("%d", v[i]);
	}
	printf("\n");

	return 0;
}