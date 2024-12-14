#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

int H, W;
vector<int> dx{1, -1, 0, 0}, dy{0, 0, 1, -1};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    ll X, P, Q;
    cin >> H >> W >> X >> P >> Q;
    P--; Q--;

    vector<vector<ll>> S(H, vector<ll>(W, 0));
    for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> S[i][j];
    ll tmp = S[P][Q];
    vector<vector<bool>> reached(H, vector<bool>(W, false));
    reached[P][Q] = true;
    priority_queue<pair<ll, pair<int,int>>, vector<pair<ll, pair<int,int>>>, greater<pair<ll, pair<int,int>>>> PQ;
    for (int k = 0; k < 4; k++) {
        int x = P + dx[k], y = Q + dy[k];
        if (is_in(x, y) && !reached[x][y]) {
            PQ.push({S[x][y], make_pair(x, y)});
            reached[x][y] = true;
        }
    }

    while (!PQ.empty()) {
        auto [power, p] = PQ.top();
        PQ.pop();

        if (power <= (tmp-1)/X) {
            tmp += power;
            int a = p.first, b = p.second;
            for (int k = 0; k < 4; k++) {
                int x = a + dx[k], y = b + dy[k];
                if (is_in(x, y) && !reached[x][y]) {
                    reached[x][y] = true;
                    PQ.push({S[x][y], make_pair(x, y)});
                }
            }
        } else {
            break;
        }
    }

    cout << tmp << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
