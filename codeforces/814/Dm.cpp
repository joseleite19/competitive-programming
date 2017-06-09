#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

struct circle {
        ll x, y, r;
            circle() {
                    }
                circle(ll _x, ll _y, ll _r) : x(_x), y(_y), r(_r) {}
};

const int MAX = 1e3 + 5;
constexpr double PI = acos(-1.0);
int n;
int in[MAX];

double area(const circle &c) {
        return PI * c.r * c.r;
}

double euclid(ll xa, ll ya, ll xb, ll yb) {
        return hypot(xa - xb, ya - yb);
}

double memo[MAX][2][2];
bool visited[MAX][2][2];
double a[MAX];
vector<int> adj[MAX];

double roll(int idx, int left, int right) {
        double &ans = memo[idx][left][right];
            if(visited[idx][left][right]) {
                        return ans;
                            }
                visited[idx][left][right] = true;
                    ans = -1e18;
                        double total_left = 0.0, total_right = 0.0;
                            for(auto &each : adj[idx]) {
                                        total_left += roll(each, (left + 1) & 1, right);
                                                total_right += roll(each, left, (right + 1) & 1);
                                                    }
                                ans = max(total_left + ((left & 1) ? -a[idx] : a[idx]), total_right + ((right & 1) ? -a[idx] : a[idx]));
                                    return ans;
}

int main() {
    scanf("%d", &n);
    vector<circle> circles;
    fori(i, 0, n) {
        ll x, y, r;
        scanf("%lld %lld %lld", &x, &y, &r);
        circles.emplace_back(x, y, r);
    }

    sort(circles.begin(), circles.end(), [&] (const circle &lhs, const circle &rhs) {
            return area(lhs) > area(rhs);
            });

    fori(i, 0, n) {
        a[i] = area(circles[i]);
    }

    fori(i, 0, n) {
        ford(j, i - 1, 0) {
            if(euclid(circles[i].x, circles[i].y, circles[j].x, circles[j].y) <= circles[j].r) {
                adj[j].push_back(i);
                in[i]++;
                break;
            }
        }
    }

    double ans = 0.0;
    fori(i, 0, n) {
        if(in[i] == 0) {
            ans += roll(i, 0, 0);
        }
    }

    printf("%.15lf\n", ans);

    return 0;
}
