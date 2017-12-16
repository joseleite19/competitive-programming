
#include <bits/stdc++.h>

using namespace std;
int inf = 0x7FFFFFFF;


int main(){
		
	int n;
	vector<int> odd;
	vector<int> nodd;
	vector<int> neven;
	vector<int> even;
	cin >> n;
	int aux;
	for (int i = 0; i < n; ++i)
	{
		cin >> aux;
		if(aux & 1)
			if(aux < 0)
				nodd.push_back(aux);
			else
				odd.push_back(aux);
		else
			if(aux < 0)
				neven.push_back(aux);
			else
				even.push_back(aux);
	}

	sort(odd.begin(),odd.end(),greater<int>());
	sort(nodd.begin(),nodd.end(),greater<int>());
	sort(even.begin(),even.end(),greater<int>());

	long long sum = 0;
	for(int e:even){
		if(e > 0)
			sum += e;
	}
	for(int o:odd){
		sum += o;
	}
	if(sum & 1){
		printf("%lld\n",sum );
		return 0;
	}
	if( odd.size() == 0 or (nodd.size() > 0)  and (abs(nodd[0]) < odd[odd.size()-1])){
		sum += nodd[0];
	}
	else{
		sum -= odd[odd.size()-1];
	}
	cout << sum <<  endl;








}