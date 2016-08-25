#include <iostream>
#include <queue>
using namespace std;

#define INF 1000000000

int inverted(int c){
	int r = 0;
	while(c != 0){
		r *= 10;
		r += c%10;
		c /= 10;
	}
	return r;
}

int main(){
	int i, a, b, c, n, dist[10000];
	cin >> n;
	while(n--){
		cin >> a >> b;
		for(i = 0; i < 10000; i++)
			dist[i] = INF;
		queue<int> s;
		s.push(a);
		dist[a] = 0;
		while(!s.empty()){
			c = s.front();
			s.pop();
			if(c == b)
				break;
			else{
				if(dist[inverted(c)] == INF){
					dist[inverted(c)] = dist[c] + 1;
					s.push(inverted(c));
				}
				if(dist[c + 1] == INF){
					dist[c + 1] = dist[c] + 1;
					s.push(c + 1);
				}
			}
		}

		cout << dist[b] << endl;

	}
	return 0;
}