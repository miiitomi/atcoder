// https://atcoder.jp/contests/abc140/tasks/abc140_d
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using mint = modint998244353;
const ll INF = 2e+18;
const ll MOD = 998244353;

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<pair<char, int>> V;
    for (int i = 0; i < N; i++) {
        char c;
        cin >> c;
        if (V.empty()) {
            V.push_back({c, 1});
        } else if (c == V.back().first) {
            V.back().second++;
        } else if (V.size() >= 2 && K > 0) {
            int x = V.back().second;
            V.pop_back();
            V.back().second += x+1;
            K--;
        } else {
            V.push_back({c, 1});
        }
    }
    while (V.size() >= 2 && K > 0) {
        K--;
        ll x = V.back().second;
        V.pop_back();
        V.back().second += x;
    }
    ll ans = 0;
    for (auto v : V) ans += v.second-1;
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
