#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

ll H, W;
vector<pair<ll,ll>> d{
    {0, 0},
    {2, 1},
    {1, 2},
    {-1, 2},
    {-2, 1},
    {-2, -1},
    {-1, -2},
    {1, -2},
    {2, -1}
};
bool is_in(int x, int y) {return 0 <= x && x < H && 0 <= y && y < W;}
int to_int(int x, int y) {return x*W + y;}
pair<int,int> to_xy(int i) {return make_pair(i/W, i%W);}

void solve() {
    ll N, M;
    cin >> N >> M;
    H = N;
    W = N;
    set<pair<ll,ll>> st;
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--; b--;
        for (auto &p : d) {
            ll x = a + p.first, y = b + p.second;
            if (!is_in(x, y)) continue;
            st.insert(make_pair(x, y));
        }
    }
    ll ans = N*N - st.size();
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}
