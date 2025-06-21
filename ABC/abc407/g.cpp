#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll H, W;
    cin >> H >> W;
    mcf_graph<ll,ll> g(H*W + 2);
    ll s = H*W, t = H*W+1;
    vector<vector<ll>> A(H, vector<ll>(W));
    ll sum = 0;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> A[i][j];
            sum += A[i][j];
        }
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if ((i+j)%2) {
                g.add_edge(i*W+j, t, 1, 0);
                continue;
            }
            g.add_edge(s, i*W+j, 1, 0);
            if (j > 0) g.add_edge(i*W+j, i*W+j-1, 1, (ll)1e+13 + A[i][j] + A[i][j-1]);
            if (j+1 < W) g.add_edge(i*W+j, i*W+j+1, 1, (ll)1e+13 + A[i][j] + A[i][j+1]);
            if (i > 0) g.add_edge(i*W+j, (i-1)*W+j, 1, (ll)1e+13 + A[i][j] + A[i-1][j]);
            if (i+1 < H) g.add_edge(i*W+j, (i+1)*W+j, 1, (ll)1e+13 + A[i][j] + A[i+1][j]);
        }
    }
    auto v = g.slope(s, t);
    ll ans = sum;
    for (int i = 0; i < (int)v.size()-1; i++) {
        ll lx = v[i].first, rx = v[i+1].first;
        ll ly = v[i].second, ry = v[i+1].second;
        for (ll x = lx + 1; x <= rx; x++) {
            ll y = ly + ((ry-ly)/(rx-lx))*(x-lx);
            ans = max(ans, sum - (y - x*(ll)1e+13));
        }
    }
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
