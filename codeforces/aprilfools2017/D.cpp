#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(vector<int> s){
	for(int i = 0; i < s.size()/2; i++){
		if(s[i] != s[s.size() - 1 - i])
			return false;
	}

	return true;
}

char dig(int n){
	if(n < 10) return '0' + n;
	n -= 10;
	if(n < 26) return 'A' + n;
	n -= 26;
	return 'a' + n;
}

vector<int> conv(long long num, int base){
	vector<int> ret;
	if(num){
		ret = conv(num/base, base);
		ret.push_back(num % base);
	}
	return ret;
}

bool is_prime(int n){
	if(!n) return 0;

	for(int i = 2; i*i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

int main(){
	long long n;

	scanf("%lld", &n);

	int cnt = 0;

	for(int i = 2; i <= 62; i++)
		cnt += is_palindrome(conv(n, i));

	printf("%s\n", is_prime(cnt) ? "Yes" : "No");
		// printf("%d %d\n", i, is_palindrome(conv(n, i)));



	return 0;
}