#include <bits/stdc++.h>
 
#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
 
const int MAX = 1e2 + 5;
int N, M;
int cap[MAX][MAX], temp_cap[MAX][MAX];
vector<int> adj[MAX];
int from[MAX], mark[MAX];
int pass = 1;
 
int bfs(int source, int sink) {
	    from[source] = source;
		    queue<int> q;
			    q.push(source);
				    mark[source] = pass;
					    bool found = false;
						    while(!found && !q.empty()) {
								        auto cur = q.front();
										        q.pop();
												 
												        for(auto &each : adj[cur]) {
															            if(mark[each] != pass && temp_cap[cur][each] > 0) {
																			                from[each] = cur;
																							                if(each == sink) {
																												                    found = true;
																																	                    break;
																																						                }
																											                q.push(each);
																															                mark[each] = pass;
																																			            }
																		        }
														    }
							 
							    int cur = sink;
								    int pc = 1 << 30;
									    while(from[cur] != cur) {
											        int prev = from[cur];
													        pc = min(pc, temp_cap[prev][cur]);
															        cur = prev;
																	    }
										 
										    cur = sink;
											    while(from[cur] != cur) {
													        int prev = from[cur];
															        temp_cap[prev][cur] -= pc;
																	        temp_cap[cur][prev] += pc;
																			        cur = prev;
																					    }
												 
												    return (pc == (1 << 30)) ? 0 : pc;
}
 
int max_flow(int source, int sink) {
	    memcpy(temp_cap, cap, sizeof cap);
		    int f = 0;
			    int pc = 0;
				    do {
						        pc = bfs(source, sink);
								        f += pc;
										        pass++;
												    } while(pc > 0);
					    return f;
}
 
int main() {
	    int t;
		    scanf("%d", &t);
			    while(t--) {
					        scanf("%d %d", &N, &M);
							        fori(i, 1, N + 1) {
										            adj[i].clear();
													        }
									        memset(cap, 0, sizeof cap);
											        fori(i, 1, M + 1) {
														            int u, v, c;
																	            scanf("%d %d %d", &u, &v, &c);
																				            adj[u].push_back(v);
																							            adj[v].push_back(u);
																										            cap[u][v] = cap[v][u] = c;
																													        }
													        int ans = 1 << 30;
															        fori(i, 2, N + 1) {
																		            int f = max_flow(1, i);
																					            ans = min(ans, f);
																								        }
																	        printf("%d\n", ans);
																			    }
				 
				    return 0;
}
