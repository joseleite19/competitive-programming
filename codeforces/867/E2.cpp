#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <bitset>
#include <deque>
#include <string>
#include <list>
#include <cstdlib>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 100;
typedef long long ll;
typedef long double ld;
multiset<int> st;
int n, tmp;
int main()
{
        while (~scanf("%d", &n))
                {
                            st.clear();
                                    ll ans = 0;
                                            for (int i = 0; i < n; i++)
                                                        {
                                                                        scanf("%d",&tmp);
                                                                                    if (!st.empty() && *st.begin() < tmp)
                                                                                                    {
                                                                                                                        ans += (ll)(tmp - *st.begin());
                                                                                                                                        st.erase(st.begin());
                                                                                                                                                        st.insert(tmp);
                                                                                                                                                                        st.insert(tmp);
                                                                                                                                                                                    }
                                                                                                else
                                                                                                                {
                                                                                                                                    st.insert(tmp);
                                                                                                                                                }
                                                                                                        }
                                                    printf("%lld\n", ans);
                                                        }
}
