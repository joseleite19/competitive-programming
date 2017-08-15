#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair

using namespace std;

#define N 51

typedef pair <int,int> pii;

char matriz[N][N];

char ss[N];
int sz;

int n,m;

int dx[] = {0,0,1,-1};
int dy[] = {-1,1,0,0};

bool valido(int i, int j){
	if(i >= n || i < 0 || j >= m || j < 0) return false;
	
	if(matriz[i][j] == '#') return false;

	return true;
}

int dp[N][N][N];

const int oo = 1000000;

int dijkstra(int x, int y){
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            for(int k = 0; k < N; k++)
                dp[i][j][k] = oo;
    dp[x][y][0] = 0;
    deque<pair<int, pair<pair<int, int>, int> > > q; // <dist, <<i, j>, id>>
    q.push_back(mp(0, mp(mp(x, y), 0)));

    int ans = oo;

    while(!q.empty()){
        int i = q.front().ss.ff.ff, j = q.front().ss.ff.ss;
        int id = q.front().ss.ss;
        int d = -q.front().ff; q.pop_front();
        if(matriz[i][j] == 'E') ans = min(ans, d);
        if(dp[i][j][id] < d) continue;
        int ii, jj;

        if(id < sz){
            if(ss[id] == 'R'){
                ii = i, jj = j+1;
                if(!valido(ii, jj)) jj--;
                if(dp[ii][jj][id+1] > dp[i][j][id]){
                    dp[ii][jj][id+1] = dp[i][j][id];
                    q.push_front(mp(-dp[ii][jj][id+1], mp(mp(ii, jj), id+1)));
                }
            }
            if(ss[id] == 'L'){
                ii = i, jj = j-1;
                if(!valido(ii, jj)) jj++;
                if(dp[ii][jj][id+1] > dp[i][j][id]){
                    dp[ii][jj][id+1] = dp[i][j][id];
                    q.push_front(mp(-dp[ii][jj][id+1], mp(mp(ii, jj), id+1)));
                }
            }
            if(ss[id] == 'D'){
                ii = i+1, jj = j;
                if(!valido(ii, jj)) ii--;
                if(dp[ii][jj][id+1] > dp[i][j][id]){
                    dp[ii][jj][id+1] = dp[i][j][id];
                    q.push_front(mp(-dp[ii][jj][id+1], mp(mp(ii, jj), id+1)));
                }
            }
            if(ss[id] == 'U'){
                ii = i-1, jj = j;
                if(!valido(ii, jj)) ii++;
                if(dp[ii][jj][id+1] > dp[i][j][id]){
                    dp[ii][jj][id+1] = dp[i][j][id];
                    q.push_front(mp(-dp[ii][jj][id+1], mp(mp(ii, jj), id+1)));
                }                
            }
        }

        //andar com outros

        for(int qq = 0; qq < 4; qq++){
            ii = i + dx[qq], jj = j + dy[qq];
            if(valido(ii, jj)){
                if(dp[ii][jj][id] > 1+dp[i][j][id]){
                    dp[ii][jj][id] = 1+dp[i][j][id];
                    q.push_back(mp(-dp[ii][jj][id], mp(mp(ii, jj), id)));
                }
            }
        }
    }
    return ans;
}

int main(){

	scanf("%d %d", &n, &m);

	int ii,jj;

	for(int i = 0; i < n; i++){
		scanf(" %s", matriz[i]);
		for(int j = 0; j < m; j++){
			if(matriz[i][j] == 'R'){
				ii = i;
				jj = j;
			}
		}
	}

    scanf(" %s", ss);
    sz = strlen(ss);

    memset(dp, -1, sizeof dp);

	printf("%d\n", dijkstra(ii, jj));

	return 0;
}
