#include <bits/stdc++.h>

using namespace std;

int main(){
	long long a, b, c, d, t, r, l, k;

	cin >> a >> b >> c >> d >> k;

	r = min(b, d);
	l = max(a, c);

	if(l > r) cout << "0\n";
	else{
		t = r - l + 1;
		if(l <= k && k <= r) t--;
		cout << t << endl;
	}

	return 0;
}